// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

vector<pll> V;
vector<ll> ans;
int mk[N];

vector<int> G[N];

void Main(){
	
	ll n, m;
	cin >> n >> m;
	fill(mk, mk + n + 1, 0); V.clear();
	for(int i = 1; i <= n; i++) G[i].clear();
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		V.pb({v, u});
		G[u].pb(v);
	}
	sort(all(V));
	for(auto x : V){
		v = x.F; u = x.S;
		if((mk[v] == 2) || (mk[u] == 2)) continue;
		if(mk[v] == 1) continue;
		mk[v] = 1;
		for(auto adj : G[v]) mk[adj] = 2;
	}
	ans.clear();
	for(int i = 1; i <= n; i++) if(mk[i] == 2) ans.pb(i);
	cout << ans.size() <<'\n';
	for(auto x : ans) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}