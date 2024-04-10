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

vector<pll> G[N];
int ans[N];
int la = 0;
void DFS(ll u, ll p){
	for(auto e : G[u]){
		if(e.F != p){
			ans[e.S] = la ++;
			DFS(e.F, u);
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	ll mx = 1;
	for(int i = 2; i <= n; i++) if(G[i].size() > G[mx].size()) mx = i;
	for(auto x : G[mx]){
		ans[x.S] = la ++;
	}
	for(auto x : G[mx]) DFS(x.F, mx);

	for(int i = 1; i < n; i++) cout << ans[i] << '\n';
	return 0;
}