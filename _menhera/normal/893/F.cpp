#include<bits/stdc++.h>

using namespace std;

struct Node
{
	Node *l; Node *r;
	int s; int e; int v;
};

int getv(const Node *p, int l, int r)
{
	// printf("%d %d %d\n", p->s, p->e, p->v);
	int s = p->s, e = p->e;
	if(l <= s && e <= r) return p->v;
	if(e < l || r < s) return INT_MAX;
	return min(getv(p->l, l, r), getv(p->r, l, r));
}

Node* setv(const Node* p, int idx, int v)
{
	// printf("%d %d %d %d\n",p->s, p->e, idx, v);
	Node* ret = new Node(*p);
	if(p->s == p->e)
		ret->v = v;
	else
	{
		int m = (p->s+p->e)/2;
		if(idx <= m) ret->l = setv(p->l, idx, v);
		else ret->r = setv(p->r, idx, v);
		ret->v = min(ret->l->v, ret->r->v);
	}
	return ret;
}

Node* init(int s, int e)
{
	Node *n = new Node;
	n->l = nullptr, n->r = nullptr, n->s = s, n->e = e, n->v = INT_MAX;
	if(s != e)
	{
		int m = (e+s)/2;
		n->l = init(s, m);
		n->r = init(m+1, e);
	}
	return n;
}


int N, r;
vector<int> conn[101010];
vector<int> H[101010];
int L[101010], R[101010], A[101010], Hn[101010], tp = -1;

void dfs(int a, int p, int h)
{
	L[a] = ++tp, H[h].push_back(a); Hn[a] = h;
	for(auto x: conn[a]) if(x != p)
		dfs(x, a, h+1);
	R[a] = tp;
}

Node* tree[101010];
int maxH = 0;
int solve(int x, int k)
{
	int l = L[x], r = R[x], h = min(maxH, Hn[x] + k);
	// printf("%d %d %d\n", l, r, h);
	return getv(tree[h], l, r);
}


int main()
{
	scanf("%d%d", &N, &r);
	for(int i=1; i<=N; ++i) scanf("%d", A+i);
	for(int i=0; i<N-1; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	dfs(r, 0, 1);

	/*
	for(int i=1; i<=N; ++i) printf("%d %d %d\n", i, L[i], R[i]);
	for(int i=1; i<=N; ++i)
	{
		printf("%d: ", i); for(auto x: H[i]) printf(" %d ", x); puts("");
	}
	*/


	tree[0] = init(0, N-1);
	for(int i=1; i<=N; ++i)
	{
		if(H[i].size()) maxH = i; else break;

		Node* ptree = tree[i-1];
		for(auto v: H[i]) ptree = setv(ptree, L[v], A[v]);
		tree[i] = ptree;
	}

	int Q; scanf("%d", &Q); int last = 0;
	while(Q--)
	{
		int p, q; scanf("%d%d", &p, &q);
		int x = (p+last)%N+1, k = (q+last)%N;

		last = solve(x, k);
		printf("%d\n", last);
	}

}