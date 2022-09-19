// nemibinam invara kasi mesl khodemono !
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
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, m, k;
int c[N];

int mk[N], dep[N];
bool fl;

int n2 = 0;
vector<int> V[2], G[N], H[N];


void DFS2(int u, int d){
	dep[u] = d;
	mk[u] = 1;
	for(auto adj : H[u]){
		//cerr <<"#" << adj << ' ' << u << ' ' << mk[adj] << ' ' << dep[adj] << ' ' << dep[u] << '\n';
		if(mk[adj]){
			if(dep[adj] % 2 == dep[u] % 2){
				fl = true;
			}
		} else {
			DFS2(adj, d + 1);
		}
	}
}

void DFS1(int u, int d){
	V[d&1].pb(u);

	dep[u] = d;
	mk[u] = 1;
	for(auto adj : G[u]){
		if(mk[adj]){
			if(dep[adj] % 2 == dep[u] % 2){
				fl = true;
			}
		} else {
			DFS1(adj, d + 1);
		}
	}
}

typedef pair<int, int> pii;

map<pii, vector<pii>> mp;
int bad[N], com[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> c[i];

	int u, v;
	vector<pll> E;

	for(int i = 0; i < m; i++){
		cin >> u >> v;
		if(c[u] == c[v]){
			G[u].pb(v);
			G[v].pb(u);
		} else {
			mp[{min(c[u], c[v]), max(c[u], c[v])}].pb({u, v});
		}
	}
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		fl = false;
		V[0].clear();
		V[1].clear();
		DFS1(i, 0);
		if(fl == true){
			bad[c[i]] = 1;
		}
		for(auto x : V[0]){
			com[x] = n2;
		}
		n2 ++;
		if(!V[1].empty()){
			H[n2].pb(n2 - 1);
			H[n2 - 1].pb(n2);
			//cerr << "! " << n2 - 1 << ' ' << n2 << '\n';
			for(auto x:V[1])
				com[x] = n2;
			n2 ++;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= k; i++) if(!bad[i]) cnt ++;
	//debug(cnt);
	ll ans = 1ll * cnt * (cnt - 1) / 2ll;
	vector<int> nd;
	for(auto [o, vec] : mp){
		if(bad[o.F]) continue;
		if(bad[o.S]) continue;
		//if(o != pii(2, 3)) continue;
		nd.clear();
		for(auto x : vec){
			nd.pb(com[x.F]);
			nd.pb(com[x.S]);
			//debug(com[x.S]);debug(com[x.F]);
			H[com[x.S]].pb(com[x.F]);
			H[com[x.F]].pb(com[x.S]);
		}
		for(auto x : nd){
			mk[x] = 0, dep[x] = 0;
			for(auto adj : H[x])
				mk[adj] = 0, dep[adj] = 0;
		}
		fl = false;
		for(auto x : nd) if(!mk[x]) DFS2(x, 0);
		if(fl){
			//cerr << "! " << o.F << ' ' << o.S << ' ' << vec.size() << '\n';
			ans --;
		}
		for(auto x : vec){
			H[com[x.S]].pop_back();
			H[com[x.F]].pop_back();
		}
	}
	cout << ans << '\n';
	return 0;
}