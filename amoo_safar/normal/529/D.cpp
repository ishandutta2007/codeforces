#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> rec[Maxm];
multiset<pll> ms;
vector<ll> G[Maxn];
ll mk[Maxn];

void DFS(ll u, ll c){
	mk[u] = c;
	for(auto adj : G[u]) if(!mk[adj]) DFS(adj, c);
}

vector<ll> V;


int main(){
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, T;
	scanf("%lld%lld%lld", &n, &m, &T);
	int h, mt, s;
	for(int i = 0; i < n; i++){
		scanf("%2d:%2d:%2d", &h, &mt, &s);
		rec[3600 * h + 60 * mt + s].pb(i);
	}
	ll mx = 0, mn, nw, U;
	for(int i = 0; i < Maxm; i++){
		while(!ms.empty() && (ms.begin() -> F < i) ) ms.erase(ms.begin());
		for(auto x : rec[i]) ms.insert({i + T - 1, x});
		mx = max(mx, (ll) ms.size());
		if(((ll)ms.size()) <= m) continue;
		//mn = ms.begin() -> S;
		nw = ms.rbegin() -> F;
		V.clear();
		while(((ll)ms.size()) > m){
			U = ms.rbegin() -> S;
			V.pb(U);
			ms.erase(--ms.end());
		}
		mn = ms.rbegin() -> S;
		for(auto x : V){
			G[x].pb(mn);
			G[mn].pb(x);
		}
		ms.erase(--ms.end());
		ms.insert({nw, mn});		
	}
	if(mx < m) return cout << "No solution", 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) if(!mk[i]) DFS(i, ++ans);
	cout << ans << '\n';
	for(int i = 0; i < n; i++) cout << mk[i] << '\n';
	return 0;
}