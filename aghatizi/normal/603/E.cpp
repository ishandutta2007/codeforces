#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

int m , from[maxn] , to[maxn] , w[maxn] , ind[maxn];

int L[maxn] , R[maxn] , mid[maxn] , cnt;

int par[maxn];

vector<int> obj[maxn * 4];

int SZ;
pair<int , int> history[maxn * 30];

inline void merge(int a , int b)
{
	while(par[a] >= 0) 
		a = par[a];
	while(par[b] >= 0)
		b = par[b];
	if(a == b)
	{
		history[SZ++] = {-1 , -1};
		return;
	}

	if(-par[a] < -par[b])
		swap(a , b);

	history[SZ++] = {b , par[b]};
	cnt -= par[a]&1 , cnt -= par[b]&1;
	par[a] += par[b];
	par[b] = a;

	cnt += par[a]&1;
}

inline void undo()
{
	int b = history[SZ - 1].first , p = history[SZ - 1].second;
	SZ--;
	if(b == -1)
		return;

	int a = par[b];
	cnt -= par[a]&1;
	par[b] = p;
	par[a] -= par[b];
	cnt += par[a]&1 , cnt += par[b]&1;
}

void add(int l , int r , int val , int s = 0 , int e = m , int v = 1)
{
	if(l <= s && e <= r)
	{
		obj[v].pb(val);
		return;
	}
	if(r <= s || e <= l)
		return;

	int m1 = (s + e) / 2;
	add(l , r , val , s , m1 , 2 * v);
	add(l , r , val , m1 , e , 2 * v + 1);
}

void dfs(int s = 0 , int e = m , int v = 1)
{
	for(auto e : obj[v])
		merge(from[e] , to[e]);
	if(e - s < 2)
	{
		if(!cnt)
			R[s] = mid[s];
		else
			L[s] = mid[s];
	}
	else
	{
		int m1 = (s + e) / 2;
		dfs(s , m1 , 2 * v);
		dfs(m1 , e , 2 * v + 1);
	}

	for(auto e : obj[v])
		undo();
	obj[v].clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(par , -1 , sizeof par);

	int n;
	cin >> n >> m;

	vector<int> cmp;
	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b >> w[i];
		a-- , b--;

		cmp.pb(w[i]);
		from[i] = a , to[i] = b;
	}

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i < m; i++)
		w[i] = lower_bound(cmp.begin() , cmp.end() , w[i]) - cmp.begin();

	cnt = n;
	for(int _ = 0; ; _++)
	{
		bool f = 0;
		for(int i = 0; i < m; i++)
		{
			if(!_)
				L[i] = -1 , R[i] = cmp.size();
			mid[i] = (L[i] + R[i]) / 2;
			if(L[i] < mid[i] && mid[i] < R[i])
				f = 1;
		}

		if(!f)
			break;

		for(int i = 0; i < m; i++)
		{
			int R = upper_bound(mid + i , mid + m , w[i] , greater<int>()) - mid;
			add(i , R , i);
		}

		dfs();
	}

	cmp.pb(-1);
	for(int i = 0; i < m; i++)
		cout << cmp[R[i]] << endl;
}