// I'll Crush you !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n;
ll m;
ll x[N], y[N];

vector<pll> G[N];

ll dis[N];
set<pll> st;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> x[0] >> y[0];

	ll X, Y;
	cin >> X >> Y;

	for(int i = 1; i <= m; i++) cin >> x[i] >> y[i];
	m += 1;

	vector<ll> I(m);
	iota(all(I), 0);
	sort(all(I), [&](int i, int j){
		return pll(x[i], i) < pll(x[j], j);
	});
	ll w;
	for(int i = 0; i + 1 < m; i++){
		w = x[I[i + 1]] - x[I[i]];
		G[I[i]].pb({I[i + 1], w});
		G[I[i + 1]].pb({I[i], w});
	}

	iota(all(I), 0);
	sort(all(I), [&](int i, int j){
		return pll(y[i], i) < pll(y[j], j);
	});
	for(int i = 0; i + 1 < m; i++){
		w = y[I[i + 1]] - y[I[i]];
		G[I[i]].pb({I[i + 1], w});
		G[I[i + 1]].pb({I[i], w});
	}


	//////////
	memset(dis, 31, sizeof dis);
	dis[0] = 0;
	st.insert({0, 0});
	ll fr;
	ll ans = Inf;
	while(!st.empty()){
		fr = st.begin() -> S;
		st.erase(st.begin());
		ans = min(ans, dis[fr] + abs(X - x[fr]) + abs(Y - y[fr]));

		for(auto [adj, we] : G[fr]){
			if(dis[adj] > dis[fr] + we)
			{
				st.erase({dis[adj], adj});
				dis[adj] = dis[fr] + we;
				st.insert({dis[adj], adj});
			}
		}
	}
	cout << ans << '\n';
	return 0;
}