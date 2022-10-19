///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,abm,bmi,bmi2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 100'010;
const int S = 400;
vector<int> A[N];
int h[N];
bool red[N];
int plc[N];
int ans[N];
int n;

namespace rmq
{
	vector<int> vv;
	const int lgN = 20;
	int mn[lgN][2*N];
	int n;

	void init()
	{
		n = vv.size();
		Loop(i,0,n) mn[0][i] = vv[i];
		Loop(k,0,lgN-1) Loop(i,0,n-(1<<k))
			mn[k+1][i] = min(mn[k][i],mn[k][i+(1<<k)]);
	}

	int get(int l, int r)
	{
		int k = 31-__builtin_clz(r-l);
		return min(mn[k][l], mn[k][r-(1<<k)]);
	}
}

int dis(int v, int u)
{
	if(plc[v] > plc[u]) swap(v, u);
	return h[v]+h[u]-2*rmq::get(plc[v],plc[u]+1);
}

void dfs1(int v, int p, int h)
{
	::h[v] = h;
	plc[v] = rmq::vv.size();
	rmq::vv.push_back(h);
	for(int u : A[v])
		if(u != p)
			{dfs1(u, v, h+1); rmq::vv.push_back(h);}
}

void bfs()
{
	static bitset<N> vis;
	vis.reset();
	queue<int> q;
	Loop(i,0,n) if(red[i])
		q.push(i),
		ans[i] = 0,
		vis[i] = 1;
	while(q.size())
	{
		int v = q.front(); q.pop();
		for(int u : A[v])
		{
			if(vis[u]) continue;
			ans[u] = ans[v]+1;
			vis[u] = 1;
			q.push(u);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> n >> q;
	Loop(i,1,n)
	{
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	int dmy = 0;
	dfs1(0,-1,0);
	red[0] = 1;
	rmq::init();
	bfs();
	vector<int> buf;
	while(q--)
	{
		int t, v;
		cin >> t >> v; --v;
		if(t == 1){
			buf.push_back(v);
			if(buf.size() == S){
				for(int u : buf) red[u] = 1;
				bfs();
				buf.clear();
			}
		}
		if(t == 2){
			int ans = ::ans[v];
			for(int u : buf)
				ans = min(ans, dis(v, u));
			cout << ans << '\n';
		}
	}
}