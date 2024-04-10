#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

class CartesianTree {
public:
	CartesianTree() : _root(nullptr) {}

	void update(long long val) {
		_root->pr += val;
	}

	int find(long long val) {
		return find(_root, val);
	}

	void insert(long long val) {
		Node *nNode = new Node(val);
		_root = insert(_root, nNode);
	}

	~CartesianTree() {
		delete _root;
	}

private:
	struct Node {
		Node() : val(0), w(1), pr(0), p(rand()),
										left(nullptr), right(nullptr) {};
		Node(long long val) : val(val), w(1), pr(0), p(rand()), 
										left(nullptr), right(nullptr) {};
		long long val;
		int w;
		long long pr;
		int p;
		Node* left;
		Node* right;
		Node* par;

		~Node() {
			if (left)
				delete left;
			if (right)
				delete right;
		}
	};

	int getW(Node *a) {
		return (!a ? 0 : a->w);
	}

	void push(Node *a) {
		if (a) {
			if (a->left)
				a->left->pr += a->pr;
			if (a->right)
				a->right->pr += a->pr;
			a->val += a->pr;
			a->pr = 0;
		}
	}

	void relax(Node *a) {
		a->w = getW(a->left) + getW(a->right) + 1;
	}

	// Node *merge(Node *a, Node *b) {
	// 	if (!a || !b)
	// 		return (!a ? b : a);
	// 	push(a);
	// 	push(b);
	// 	if (a->p < b->p) 
	// 		swap(a, b);
	// 	if (a->val < b->val) 
	// 		a->right = merge(a->right, b);
	// 	else 
	// 		a->left = merge(a->left, b);
	// 	relax(a);
	// 	return a;
	// }

	void split(Node *root, long long x, Node *&a, Node *&b) {
		if (!root) {
			a = nullptr;
			b = nullptr;
			return;
		}
		push(root);
		if (root->val <= x) {
			split(root->right, x, root->right, b);
			a = root;
			relax(a);
		}
		else {
			split(root->left, x, a, root->left);
			b = root;
			relax(b);
		}
	}

	int find(Node* a, long long val) {
		if (!a)
			return 0;
		push(a);
		int ans = 0;
		if (a->val >= val)
			++ans;
		if (a->val < val)
			ans += find(a->right, val);
		else 
			ans += getW(a->right) + find(a->left, val);
		return ans;
	}

	Node* insert(Node* a, Node* b) {
		if (!a) 
			return b;
		push(a);

		if (a->p < b->p) {
			Node *l, *r;
			split(a, b->val, l, r);
			b->left = l;
			b->right = r;
			relax(b);
			return b;
		}

		if (a->val <= b->val) 
			a->right = insert(a->right, b);
		else 
			a->left = insert(a->left, b);
		relax(a);
		return a;
	}

	Node* _root;
};

int main() {
	int n;
	long long m;
	scanf("%d %I64d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	long long l = -1e14 - 1;
	long long r = 1e14 + 1;
	while (r - l > 1) {
		long long x = (l + r) / 2;
		CartesianTree tree;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			tree.insert(0);
			tree.update(a[i]);
			ans += (long long)tree.find(x + 1);
			// cout << ans << endl;
		}
		// cout << x << " " <<  ans << endl;
		if (ans < m)
			r = x;
		else 
			l = x; 
	}
	printf("%I64d\n", r);
	return 0;
}