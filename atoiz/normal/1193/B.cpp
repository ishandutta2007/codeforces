/*input
6 4 10
1
2
1
4
4
3 4 5
4 7 2
5 4 1
6 9 3

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100020;
int N, M, K;
vector<int> G[MAXN];
int sz[MAXN];
int D[MAXN];
long long W[MAXN];

struct Node
{
	Node *lnode = nullptr, *rnode = nullptr;
	int lo, mid, hi;
	long long cur = 0, lazy = 0;
	
	Node(int _lo = 0, int _hi = -1): lo(_lo), hi(_hi) { mid = (lo + hi) >> 1; };

	void push()
	{
		if (lnode) lnode->cur = max(lnode->cur + lazy, cur), lnode->lazy += lazy;
		if (rnode) rnode->cur = max(rnode->cur + lazy, cur), rnode->lazy += lazy;
		lazy = 0;
	}

	void merge(Node *x)
	{
		push(); x->push();
		if (x->lnode) {
			if (lnode == nullptr) lnode = new Node(lo, mid);
			lnode->push();
			lnode->cur = max(lnode->cur, cur);

			lnode->merge(x->lnode);
			delete(x->lnode);
		} else if (lnode) {
			lnode->push();
			lnode->cur += x->cur;
			lnode->lazy += x->cur;
		}

		if (x->rnode) {
			if (rnode == nullptr) rnode = new Node(mid + 1, hi);
			rnode->push();
			rnode->cur = max(rnode->cur, cur);

			rnode->merge(x->rnode);
			delete(x->rnode);
		} else if (rnode) {
			rnode->push();
			rnode->cur += x->cur;
			rnode->lazy += x->cur;
		}

		cur += x->cur;
	}

	void update(int l, int r, long long x)
	{
		push();
		if (lo > r || l > hi) return;
		if (l <= lo && hi <= r) {
			cur = max(cur, x);
			return;
		}

		if (lnode == nullptr) lnode = new Node(lo, mid);
		if (rnode == nullptr) rnode = new Node(mid + 1, hi);
		lnode->update(l, r, x);
		rnode->update(l, r, x);
	}

	long long get(int i)
	{
		push();
		if (i <= mid) return max(cur, (lnode ? lnode->get(i) : 0));
		else return max(cur, (rnode ? rnode->get(i) : 0));
	}
};

void dfs1(int u)
{
	sz[u] = (W[u] > 0);
	for (auto &v : G[u]) {
		dfs1(v);
		sz[u] += sz[v];
		if (sz[v] > sz[G[u][0]]) swap(v, G[u][0]);
	}
}

Node* dfs2(int u)
{
	Node *x;
	for (int &v : G[u]) {
		if (v == G[u][0]) x = dfs2(v);
		else {
			x->merge(dfs2(v));
		}
	}
	if (G[u].empty()) x = new Node(1, K);

	if (W[u]) {
		x->update(D[u], K, x->get(D[u]) + W[u]);
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int v = 2; v <= N; ++v) {
		int u; cin >> u;
		G[u].push_back(v);
	}
	for (int i = 0; i < M; ++i) {
		int v;
		cin >> v;
		cin >> D[v] >> W[v];
	}

	dfs1(1);
	cout << dfs2(1)->get(K) << endl;
}