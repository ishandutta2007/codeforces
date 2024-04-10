#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int b[N];

struct data
{
	//Use required attributes
	int mn;

	//Default Values
	data() : mn(1e9) {};
};

struct SegTree
{
	int N;
	vector<data> st;
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
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node]; 
		}
		st[node].mn += lazy[node];
		cLazy[node] = 0;
		lazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = b[L];
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}

	int pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(R < pos || st[node].mn >= 0)
			return 1e9;
		if(L == R)
			return L;
		int M = (L + R)/2;
		int lval = pQuery(node*2, L, M, pos);
		if(lval <= N)
			return lval;
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
		Update(node*2 + 1, M + 1, R, i, j, val);
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

	data query(int l, int r)
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

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}

	//returns first index such that pref[idx] >= val

	int search(int val)
	{
		int curSum = 0, pos = 0;
		for(int i = log2(N) + 1; i >= 0; i--)
		{
			if(pos + (1 << i) < N && curSum + bit[pos + (1 << i)] < val)
			{
				curSum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

int n, q;
int a[N], ans[N];
bool check[N];
vector<pair<int, int> > store[N];
SegTree st;
BIT bit;

void recurse(int pos)
{
	check[pos] = 0;
	st.update(pos, 1e9);
	st.update(pos + 1, n, -1);
	bit.update(pos, -1);
	int rpos = st.pQuery(1, 1, st.N, pos + 1);
	assert(pos != rpos);
	if(rpos <= n)
		return recurse(rpos);
}

int32_t main()
{
	IOS;
	cin >> n >> q;
	st.init(n + 1);
	bit.init(n);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		store[x].push_back({y, i});
	}
	int valid = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i - a[i] >= 0 && i - a[i] <= valid)
		{
			bit.update(i, 1);
			check[i] = 1;
			b[i] = valid - (i - a[i]);
			valid++;
		}
		else
			b[i] = 1e9;
	}
	st.build(1, 1, st.N);
	for(int i = 0; i <= n - 1; i++)
	{
		if(check[i])
			recurse(i);
		for(auto &it:store[i])
			ans[it.second] = bit.rsum(i, n - it.first);
	}
	for(int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}