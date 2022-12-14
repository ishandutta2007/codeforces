#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXALPHA = 2;

struct Trie {
	struct node {
		node *child[MAXALPHA];
		int sz;
	
		node() {
			for (int i = 0; i < MAXALPHA; i++)
				child[i] = nullptr;
			sz = 0;
		}

		node* getChild(int x) {
			if (this->child[x] == nullptr)
				this->child[x] = new node();
			return this->child[x];
		}
	};

	node *root;

	Trie() {
		root = new node();
		add(0);
	}

	void add(int k) {
		node *cur = root;
		for (int i = 29; i >= 0; i--) {
			int x = (k >> i) & 1;
			cur = cur->getChild(x);
			cur->sz ++;
		}
	}

	void del(int k) {
		node *cur = root;	
		for (int i = 29; i >= 0; i--) {
			int x = (k >> i) & 1;
			node *next = cur->getChild(x);
			next->sz --;
			if (next->sz == 0)
				cur->child[x] = nullptr;
			cur = next;
		}
	}

	int get(int k) {
		node *cur = root;
		int maxAnswer = 0;
		for (int i = 29; i >= 0; i--) {
			int x = (k >> i) & 1;
			if (cur->child[x^1] == nullptr)
				cur = cur->child[x];
			else {
				cur = cur->child[x^1];
				maxAnswer |= (1 << i);
			}
		}
		return maxAnswer;
	}
} T;

int main() {
	ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	while (q --) {
		char type;
		int x;
		cin >> type >> x;
		if (type == '+') {
			T.add(x);
		} else if (type == '-') {
			T.del(x);
		} else {
			cout << T.get(x) << '\n';
		}
	}
}