#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;
 
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

struct SegTree
{
	int N;
	vector<int> st;
	vector<bool> cLazy;

	void preinit()
	{
		st = vector<int> (4 * 3e5 + 1);
		cLazy = vector<bool> (4 * 3e5 + 1);
	}

	void init(int n)
	{
		N = n;
		for(int i = 0; i < 4 * N + 5; i++)
			cLazy[i] = 0;
	}

	//Write reqd merge functions
	void merge(int &cur, int &l, int &r) 
	{
		cur = l + r;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node * 2] = !cLazy[node * 2];
			cLazy[node * 2 + 1] = !cLazy[node * 2 + 1];
		}
		st[node] *= -1;
		cLazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node] = 0;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	int Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return 0;
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		int left=Query(node*2, L, M, i, j);
		int right=Query(node*2 + 1, M + 1, R, i, j);
		return left + right;
	}

	int pQuery(int node, int L, int R, int pos)
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
			st[node] = val;
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	int query(int pos)
	{
		return pQuery(1, 1, N, pos);
	}

	int query(int l, int r)
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

int n, q;
int a[N];
SegTree st;
BIT bit;

void update(int idx)
{
	if(idx < 1 || idx > n)
		return;
	if(bit.rsum(idx, idx))
	{
		bit.update(idx, -1);
		st.update(idx, 0);
		st.update(idx + 1, n, -1);
	}
	if(a[idx] > a[idx - 1] && a[idx] > a[idx + 1])
	{		
		bit.update(idx, 1);
		int prv = bit.rsum(1, idx - 1);
		if(prv % 2)
			st.update(idx, -a[idx]);
		else
			st.update(idx, a[idx]);
		st.update(idx + 1, n, 1);
	}
	if(a[idx] < a[idx - 1] && a[idx] < a[idx + 1])
	{
		bit.update(idx, 1);
		int prv = bit.rsum(1, idx - 1);
		if(prv % 2)
			st.update(idx, -a[idx]);
		else
			st.update(idx, a[idx]);
		st.update(idx + 1, n, 1);
	}
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	st.preinit();
	while(t--)
	{
		cin >> n >> q;
		st.init(n);
		bit.init(n);
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		st.build(1, 1, n);
		a[0] = 0;
		a[n + 1] = 0;
		for(int i = 1; i <= n; i++)
			update(i);
		cout << st.query(1, n) << endl;
		while(q--)
		{
			int l, r;
			cin >> l >> r;
			map<int, int> cur;
			cur[l - 1];
			cur[l];
			cur[l + 1];
			cur[r - 1];
			cur[r];
			cur[r + 1];
			swap(a[l], a[r]);
			for(auto &it:cur)
				update(it.first);
			cout << st.query(1, n) << endl;
		}
	}
	return 0;
}