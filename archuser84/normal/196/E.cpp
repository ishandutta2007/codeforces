///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 100'010;
const ll inf = 1e17;
int pors[N];
bool ispor[N];
vector<pll> A[N];
ll dis[N];
int near[N];
tuple<ll,int,int> E[N];
int n, m, k;

int par[N];
int rt(int v) {return par[v] == -1? v: (par[v] = rt(par[v]));}
bool unite(int v, int u)
{
	v = rt(v); u = rt(u);
	if (u == v)
		return 0;
	par[u] = v;
	return 1;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop (i,0,m) {
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		A[v].push_back({u,w});
		A[u].push_back({v,w});
		E[i] = {w, v, u};
	}
	cin >> k;
	Loop (i,0,k) {
		cin >> pors[i]; --pors[i];
		ispor[pors[i]] = 1;
	}
	set<pll> s;
	fill(dis, dis+N, inf);
	Loop (i,0,k) {
		dis[pors[i]] = 0;
		near[pors[i]] = pors[i];
		s.insert({0, pors[i]});
	}
	while (s.size()) {
		int v = s.begin()->second;
		s.erase(s.begin());
		for (auto [u, w] : A[v]) {
			if (dis[v] + w < dis[u]) {
				s.erase({dis[u], u});
				dis[u] = dis[v] + w;
				near[u] = near[v];
				s.insert({dis[u], u});
			}
		}
	}
	Loop (i,0,m) {
		auto &[w, v, u] = E[i];
		w = dis[v] + dis[u] + w;
		v = near[v];
		u = near[u];
	}
	sort(E, E+m);
	ll ans = dis[0];
	memset(par, -1, sizeof(par));
	Loop (i,0,m) {
		auto &[w, v, u] = E[i];
		if (unite(v, u))
			ans += w;
	}
	cout << ans << '\n';
}