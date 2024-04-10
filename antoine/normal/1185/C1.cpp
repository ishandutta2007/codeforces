#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

struct BST {

private:

	struct Node {
		int val, height = 0, cnt = 1, sum = 0;
		Node *left = nullptr, *right = nullptr;

		explicit Node(const int val) :
				val(val), sum(val) {
		}

		void updateVars() {
			height = 0, cnt = 1, sum = val;
			for (const Node *child : { left, right })
				if (child) {
					height = max(height, child->height + 1);
					cnt += child->cnt;
					sum += child->sum;
				}
		}
	};

	void rotateLeft(Node *&x) {
		Node * const y = x->right;
		x->right = y->left;
		y->left = x;
		x->updateVars();
		y->updateVars();
		x = y;
	}

	void rotateRight(Node *&x) {
		Node * const y = x->left;
		x->left = y->right;
		y->right = x;
		x->updateVars();
		y->updateVars();
		x = y;
	}

	void balance(Node *&node) {
		const auto height = [](const Node *node) {
			return node ? node->height : -1;
		};

		const int diff = height(node->left) - height(node->right);
		if (diff > 1) { // left heavy
			Node *&x = node->left;
			if (height(x->left) < height(x->right))
				rotateLeft(x);
			rotateRight(node);
		} else if (diff < -1) { // right heavy
			Node *&x = node->right;
			if (height(x->right) < height(x->left))
				rotateRight(x);
			rotateLeft(node);
		}
		assert((height(node->left) - height(node->right)) <= 1);
	}

	void insert(Node *&node, const int val) {
		if (node == nullptr)
			node = new Node(val);
		else {
			if (val < node->val)
				insert(node->left, val);
			else
				insert(node->right, val);
			node->updateVars();
			balance(node);
		}
	}

	int sumAtRank(Node *node, int k) const {
		int res = 0;
		for (;;) {
			if (node->left) {
				if (k < node->left->cnt) {
					node = node->left;
					continue;
				}
				k -= node->left->cnt;
			}
			res += node->val + (node->left ? node->left->sum : 0);

			if (k == 0)
				return res;
			k--;
			node = node->right;
		}
	}

	Node *root = nullptr;

public:

	int size() const {
		return root ? root->cnt : 0;
	}

	void insert(const int val) {
		insert(root, val);
	}

	int sumAtRank(const int k) const {
		assert(0 <= k && k < size());
		return sumAtRank(root, k);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, M;
	cin >> n >> M;

	BST bst;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		int lo = 0, hi = bst.size();
		while (lo < hi) {
			const int mid = (lo + hi + 1) / 2;
			if (bst.sumAtRank(mid - 1) + x <= M)
				lo = mid;
			else
				hi = mid - 1;
		}
		cout << bst.size() - lo << ' ';
		bst.insert(x);
	}
	return 0;
}