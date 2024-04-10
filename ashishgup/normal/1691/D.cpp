#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N];

struct data
{
	//Use required attributes
	int prefsum, sufsum, sum, maxsum;
 
	//Default Values
	data() : prefsum(-2e15), sufsum(-2e15), sum(-2e15), maxsum(-2e15) {};
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
		if(l.prefsum == -2e15)
			cur = r;
		else if(r.prefsum == -2e15)
			cur = l;
		else
		{
			cur.sum = l.sum + r.sum;
			cur.prefsum = max(l.prefsum, l.sum + r.prefsum);
			cur.sufsum = max(r.sufsum, l.sufsum + r.sum);
			cur.maxsum = max(max(l.maxsum, r.maxsum), l.sufsum + r.prefsum);		
		}
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
			st[node].sum = a[L];
			st[node].prefsum = a[L];
			st[node].sufsum = a[L];
			st[node].maxsum = a[L];
			return;
		}
		int M = (L + R)/2;
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
		data left = Query(node*2, L, M, i, j);
		data right = Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}
 
	data pQuery(int node, int L, int R, int pos)
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
 
	data query(int pos)
	{
		return pQuery(1, 1, N, pos);
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
 
 struct data2
{
	//Use required attributes
	int mx, idx;

	//Default Values
	data2() : mx(-2e9) {};
};

struct SegTree2
{
	int N;
	vector<data2> st;
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
	void merge(data2 &cur, data2 &l, data2 &r) 
	{
		cur.mx = max(l.mx, r.mx);
		if(l.mx >= r.mx)
			cur.idx = l.idx;
		else
			cur.idx = r.idx;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].mx = lazy[node];
		cLazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mx = a[L];
			st[node].idx = L;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data2 Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data2();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data2 left=Query(node*2, L, M, i, j);
		data2 right=Query(node*2 + 1, M + 1, R, i, j);
		data2 cur;
		merge(cur, left, right);
		return cur;
	}

	data2 pQuery(int node, int L, int R, int pos)
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

	data2 query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}

	data2 query(int l, int r)
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

SegTree st;
SegTree2 mxSt;
int flag = 0;

void divide(int l, int r)
{
	if(r <= l)
		return;
	if(!flag)
		return;
	data2 maxVal = mxSt.query(l, r);
	int m = maxVal.idx;
	data leftVal = st.query(l, m);
	data rightVal = st.query(m, r);
	int maxSum = leftVal.sufsum + rightVal.prefsum - a[m];
	// cerr << leftVal.sufsum << endl;
	// cerr << m << " " << maxSum << endl;
	if(maxSum > a[m])
	{
		flag = 0;
		return;
	}
	divide(l, m - 1);
	divide(m + 1, r);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		flag = 1;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		st.init(n);
		st.build(1, 1, n);
		mxSt.init(n);
		mxSt.build(1, 1, n);
		divide(1, n);
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
};