///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 2010;
const ll inf = 1e17;
vector<pll> A[N];
ll mn = inf;
int n;


ll dis[N];
void dij()
{
	set<pll> s;
	Loop (v,0,n) {
		dis[v] = inf;
		for (auto [u, w] : A[v])
			dis[v] = min(dis[v], 2 * (w - mn));
		s.insert({dis[v], v});
//		cout << dis[v] << "!\n";
	}
	while (s.size()) {
		auto [d, v] = *s.begin();
		s.erase(s.begin());
		for (auto [u, w] : A[v]) {
			if (d+w-mn < dis[u]) {
				s.erase({dis[u], u});
				dis[u] = d+w-mn;
				s.insert({dis[u], u});
			}
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n) Loop (j,i+1,n) {
		ll w;
		cin >> w;
		A[i].push_back({j,w});
		A[j].push_back({i,w});
		mn = min(mn, w);
	}
	dij();
	Loop (i,0,n)
		cout << dis[i] + mn*(n-1) << '\n';
}