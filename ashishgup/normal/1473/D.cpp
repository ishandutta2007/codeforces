//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

struct data
{
	//Use required attributes
	int mn, mx;

	//Default Values
	data() : mn(1e9), mx(-1e9) {};
};

int n, m;
int prefBal[N], prefMn[N], prefMx[N], ans[N];
int sufBal[N], sufMn[N], sufMx[N];
char s[N];
vector<pair<int, int> > r[N];


struct SegTree
{
	int N;
	vector<data> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n)
	{
		N = n;
		st = vector<data> (4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
		cur.mx = max(l.mx, r.mx);
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
		st[node].mx += lazy[node];
		lazy[node] = 0;
		cLazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = prefBal[L];
			st[node].mx = prefBal[L];
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

	void Update(int node, int L, int R, int i, int j, int mn)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = mn;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, mn);
		Update(node*2 + 1, M + 1, R, i, j, mn);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, int mn)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = mn;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, mn);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, mn);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}

	data query(int l, int r)
	{
		if(l > r)
			return data();
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int mn)
	{
		pUpdate(1, 1, N, pos, mn);
	}

	void update(int l, int r, int mn)
	{
		Update(1, 1, N, l, r, mn);
	}
};


int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			r[i].clear();
			cin >> s[i];
		}
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			r[y].push_back({x, i});
		}
		SegTree st;
		for(int i = 1; i <= n; i++)
		{
			prefBal[i] = prefBal[i - 1] + (s[i] == '+') - (s[i] == '-');
			prefMn[i] = min(prefMn[i - 1], prefBal[i]);
			prefMx[i] = max(prefMx[i - 1], prefBal[i]);
		}
		st.init(n);
		st.build(1, 1, n);
		for(int i = 1; i <= n; i++)
		{
			int val = 0;
			if(s[i] == '+')
				val = -1;
			else
				val = +1;
			st.update(i, n, val);
			for(auto &cur:r[i])
			{
				int l = cur.first;
				int lftmx = prefMx[l - 1];
				int lftmn = prefMn[l - 1];
				int lftBal = prefBal[l - 1];
				data curr = st.query(i + 1, n);
				int mx = max(lftmx, lftBal + curr.mx);
				int mn = min(lftmn, lftBal + curr.mn);
				//cout << lftmx << " " << lftmn << " " << mx << " " << mn << " " << curr.mx << " " << curr.mn << endl;
				ans[cur.second] = mx - mn + 1;
			}
		}
		for(int i = 1; i <= m; i++)
			cout << ans[i] << endl;
	}
	return 0;
}