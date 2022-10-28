#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int SZ = 2;
 
int add(int a, int b)
{
	int res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}
 
int mult(int a, int b)
{
	long long res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}
 
struct matrix
{
	int arr[SZ][SZ];
 
	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}
 
	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}
 
	void init()
	{
		reset();
		arr[0][0] = arr[0][1] = arr[1][0] = 1;
	}
 
	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
			}
		}
		return res;
	}
 
	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = add(res.arr[i][j] , mult(arr[i][k] , o.arr[k][j]));
				}
			}
		}
		return res;
	}
};
 
matrix power(matrix a, int b)
{
	matrix res;
	res.makeiden();
	while(b)
	{
		if(b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}
 
struct data
{
	//Use required attributes
	struct matrix cur;
 
	data() {
		cur.reset();
	}
};
 
int a[N];
matrix fib;
struct data stored;
 
void print(matrix &m)
{
	for(int i = 0; i < SZ; i++)
	{
		for(int j = 0; j < SZ; j++)
			cerr << m.arr[i][j] << " ";
		cerr << endl;
	}
	cerr << endl;
}
 
struct SegTree
{
	int N;
	vector<struct data> st;
	vector<bool> cLazy;
	vector<struct data> lazy;
 
	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.resize(4 * N + 5);
		for(int i = 0; i < 4 * N + 5; i++)
			lazy[i].cur.makeiden();
	}
 
	//Write reqd merge functions
	void merge(struct data &cur, struct data &l, struct data &r) 
	{
		cur.cur = l.cur + r.cur;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node * 2].cur = lazy[node * 2].cur * lazy[node].cur;
			lazy[node * 2 + 1].cur = lazy[node * 2 + 1].cur * lazy[node].cur; 
		}
		st[node].cur = st[node].cur * lazy[node].cur;
		cLazy[node] = 0;
		lazy[node].cur.makeiden();
	}
 
	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].cur = power(fib, a[L] - 1);
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}
 
	struct data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return stored;
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		struct data left=Query(node*2, L, M, i, j);
		struct data right=Query(node*2 + 1, M + 1, R, i, j);
		struct data cur;
		merge(cur, left, right);
		return cur;
	}
 
	struct data pQuery(int node, int L, int R, int pos)
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
			lazy[node].cur = lazy[node].cur * power(fib, val);
			propagate(node, L, R);
			return;
		}
		int M = (L + R) / 2;
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
			lazy[node].cur = lazy[node].cur * power(fib, val);
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
 
	struct data query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}
 
	struct data query(int l, int r)
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
 
int n, m;
 
int32_t main()
{
	IOS;
	fib.init();
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	SegTree st;
	st.init(n);
	st.build(1, 1, n);
	for(int i = 1; i <= m; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l, r, x;
			cin >> l >> r >> x;
			st.update(l, r, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r).cur.arr[0][0] << endl;
		}
	}
	return 0;
}