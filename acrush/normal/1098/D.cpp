#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi = acos(-1.0);
const double eps = 1e-11;
template<class T> inline void ckmin(T &a, T b) { if (b<a) a = b; }
template<class T> inline void ckmax(T &a, T b) { if (b>a) a = b; }
template<class T> inline T sqr(T x) { return x * x; }
typedef pair<int, int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

const int MAX_NUM_NODES = (1 << 20);

struct Node
{
	int key;
	int size = 0;
	int cnt = 0;
	int64 sum = 0;
	Node *child[2];
	Node *parent;

	void sync()
	{
		size = child[0]->size + child[1]->size + cnt;
		sum = (int64)key * cnt + child[0]->sum + child[1]->sum;
	}
};
Node nil_node_ins;
Node *nil_node = &nil_node_ins;

struct Splay
{
	Node *root;

	static int num_nodes;
	static Node node_buffer[MAX_NUM_NODES];
	static Node* new_node() { return &node_buffer[num_nodes++]; }

	Splay()
	{
		reset();
	}
	void reset()
	{
		root = nil_node;
	}
	void rotate(Node *x, bool to_right)
	{
		Node *y = x->parent;
		y->child[!to_right] = x->child[to_right];
		if (x->child[to_right] != nil_node) x->child[to_right]->parent = y;
		x->parent = y->parent;
		if (y->parent != nil_node) y->parent->child[y == y->parent->child[to_right] ? to_right : !to_right] = x;
		x->child[to_right] = y;
		y->parent = x;
		y->sync();
		x->sync();
	}
	void splay(Node *x, Node *target)
	{
		Node *y;
		while (x->parent != target)
		{
			y = x->parent;
			if (x == y->child[0])
			{
				if (y->parent != target && y == y->parent->child[0]) rotate(y, true);
				rotate(x, true);
			}
			else
			{
				if (y->parent != target && y == y->parent->child[1]) rotate(y, false);
				rotate(x, false);
			}
		}
		if (target == nil_node) root = x;
	}

	void insert(int key)
	{
		if (root == nil_node)
		{
			root = new_node();
			root->child[0] = root->child[1] = root->parent = nil_node;
			root->key = key;
			root->size = root->cnt = 1;
			return;
		}
		Node *x = root, *y;
		while (1)
		{
			x->size++;
			if (key == x->key)
			{
				x->cnt++;
				x->sync();
				y = x;
				break;
			}
			else if (key < x->key)
			{
				if (x->child[0] != nil_node)
					x = x->child[0];
				else
				{
					x->child[0] = new_node();
					y = x->child[0];
					y->key = key;
					y->size = y->cnt = 1;
					y->child[0] = y->child[1] = nil_node;
					y->parent = x;
					break;
				}
			}
			else
			{
				if (x->child[1] != nil_node)
					x = x->child[1];
				else
				{
					x->child[1] = new_node();
					y = x->child[1];
					y->key = key;
					y->size = y->cnt = 1;
					y->child[0] = y->child[1] = nil_node;
					y->parent = x;
					break;
				}
			}
		}
		splay(y, nil_node);
	}
	Node* search(int key)
	{
		if (root == nil_node) return nil_node;
		Node *x = root, *y = nil_node;
		while (1)
		{
			if (key == x->key) { y = x; break; }
			if (key > x->key)
			{
				if (x->child[1] == nil_node) break;
				x = x->child[1];
			}
			else
			{
				if (x->child[0] == nil_node) break;
				x = x->child[0];
			}
		}
		splay(x, nil_node);
		return y;
	}
	Node* searchmin(Node *x)
	{
		Node *y = x->parent;
		while (x->child[0] != nil_node) x = x->child[0];
		splay(x, y);
		return x;
	}
	void erase(int key)
	{
		if (root == nil_node) return;
		Node *x = search(key), *y;
		if (x == nil_node) return;
		if (x->cnt > 1)
		{
			x->cnt--;
			x->sync();
			return;
		}
		if (x->child[0] == nil_node && x->child[1] == nil_node)
		{
			reset();
			return;
		}
		if (x->child[0] == nil_node)
		{
			root = x->child[1];
			x->child[1]->parent = nil_node;
			return;
		}
		if (x->child[1] == nil_node)
		{
			root = x->child[0];
			x->child[0]->parent = nil_node;
			return;
		}
		y = searchmin(x->child[1]);
		y->parent = nil_node;
		y->child[0] = x->child[0];
		x->child[0]->parent = y;
		y->sync();
		root = y;
	}
	int size()
	{
		return (root == nil_node) ? 0 : root->size;
	}
	pair<Node*, int64> upper_bound(int key)
	{
		if (root == nil_node) return make_pair(nil_node, 0);
		Node *x = root, *y = nil_node;
		int64 prefix_sum = 0;
		while (1)
		{
			if (key >= x->key)
			{
				prefix_sum += (int64)x->key * x->cnt;
				prefix_sum += x->child[0]->sum;
				if (x->child[1] == nil_node) break;
				x = x->child[1];
			}
			else
			{
				y = x;
				if (x->child[0] == nil_node) break;
				x = x->child[0];
			}
		}
		splay(x, nil_node);
		if (y != nil_node) splay(y, nil_node);
		return make_pair(y, prefix_sum);
	}
};
int Splay::num_nodes = 0;
Node Splay::node_buffer[MAX_NUM_NODES];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int nq;
	while (cin >> nq)
	{
		Splay::num_nodes = 0;
		Splay splay;
		splay.reset();
		REP(cl, nq)
		{
			string s;
			int key;
			cin >> s >> key;
			if (s[0] == '+')
				splay.insert(key);
			else
				splay.erase(key);
			int ret = splay.size();
			int64 last = 0;
			const int INF = (1 << 30);
			while (last < INF)
			{
				pair<Node*, int64> r = splay.upper_bound(last);
				if (r.first == nil_node) break;
				if (r.first->key > r.second * 2) --ret;
				last = r.second + r.first->key;
			}
			printf("%d\n", ret);
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}