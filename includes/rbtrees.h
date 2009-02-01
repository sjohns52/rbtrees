/*
 * rbtrees.h
 *
 *
 */

#ifndef RBTREES_H_
#define RBTREES_H_

#define COLOR(color) (color == 0) ? "red" : "black"

namespace ASoliman {

class RBTree {
	public:
		//Basic Functions
		RBTree();
		RBTree(int32_t key, void *data);
		~RBTree();
		//rbtreePtr createRBTree(int, void *);
		//void destroyRBTree();
		RBTreeNode &insertNode(int32_t key, void *data);
		int32_t deleteNode(int32_t key);
		short isValidRedBlackTree();
		RBTreeNode &queryTree(int32_t key);
		int32_t size();
		int32_t maxDepth();
		RBTreeNode &getSuccessor(RBTreeNode &node);
		RBTreeNode &getPredecessor(RBTreeNode &node);
		RBTreeNode &getMinimum();
		RBTreeNode &getMaximum();

		//Visualization Functions
		void printTree();
		void printPaths();

	private:
		RBTreeNode *root_;
		// Helper Functions
		RBTreeNode &getMinimum(RBTreeNode &tree);
		RBTreeNode &getMaximum(RBTreeNode &tree);
		RBTreeNode &grandparent(RBTreeNode &node);
		RBTreeNode &createNode(RBTreeNode &parent, short loc, int32_t key,
				void *data);
		RBTreeNode &uncle(RBTreeNode &node);
		RBTreeNode &sibling(RBTreeNode &node);
		short rotateRight(RBTreeNode &node);
		short rotateLeft(RBTreeNode &node);
		short isLeaf(RBTreeNode &node);

		const short BLACK_ = 1;
		const short RED_ = 0;
		const short LEFT_ = 100;
		const short RIGHT_ = 200;
};

class RBTreeNode {
	public:
		RBTreeNode(RBTreeNode *parent, RBTreeNode *left, BRTreeNode *right, short color);
		RBTreeNode &getParent();
		RBTreeNOde &getLeft();
		RBTreeNode &getRight();
		void **getData();
		int32_t getKey();
		short getColor();
	private:
		RBTreeNode *parent_;
		RBTreeNode *left_;
		RBTreeNode *right_;
		void *data_;
		int32_t key_;
		unsigned short color_;
};

}

#endif /* RBTREES_H_ */
