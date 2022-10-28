#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, q;
int a[N], b[N], c[N];

struct value
{
	//Use required attributes
	int prefsum, sufsum, sum, maxsum, mnprefsum, mnsufsum, minsum;

	//Default Values
	value() : prefsum(-2e14), sufsum(-2e14), sum(0), maxsum(-2e14), mnprefsum(2e14), mnsufsum(2e14), minsum(2e15) {};
};

struct SegTree
{
	int N;
	vector<value> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(value &cur, value &l, value &r) 
	{
		cur.sum = l.sum + r.sum;
		cur.prefsum = max(l.prefsum, l.sum + r.prefsum);
		cur.sufsum = max(r.sufsum, l.sufsum + r.sum);
		cur.mnprefsum = min(l.mnprefsum, l.sum + r.mnprefsum);
		cur.mnsufsum = min(r.mnsufsum, r.sum + l.mnsufsum);
		cur.maxsum = max(max(l.maxsum, r.maxsum), l.sufsum + r.prefsum);	
		cur.minsum = min(min(l.minsum, r.minsum), l.mnsufsum + r.mnprefsum);
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		;//Not required
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].sum = c[L];
			st[node].prefsum = c[L];
			st[node].sufsum = c[L];
			st[node].mnprefsum = c[L];
			st[node].mnsufsum = c[L];
			st[node].maxsum = c[L];
			st[node].minsum = c[L];
			return;
		}
		int M = (L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	value Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return value();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		value left = Query(node*2, L, M, i, j);
		value right = Query(node*2 + 1, M + 1, R, i, j);
		value cur;
		merge(cur, left, right);
		return cur;
	}

	value pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	value query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}

	value query(int l, int r)
	{
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val)
	{
		pUpdate(1, 1, N, pos, val);
	}

	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};
 

int32_t main()
{
	IOS;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
		c[i] = a[i] - b[i];
	SegTree st;
	st.init(n);
	st.build(1, 1, n);
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		value store = st.query(l, r);
		if(store.sum != 0)
			cout << -1 << endl;
		else
			cout << max(store.maxsum, -store.minsum) << endl;
	}
	return 0;
}