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

const ll Mod = 998244353;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
const ll Base = 101;

ll T = 1, st[N];
vector<ll> G[N];
ll sp[N][Log], fn[N], spd[N], dep[N];;
void DFS(ll u, ll p, ll d = 0){
	st[u] = T++;
	sp[u][0] = p;
	dep[u] = d;
	for(auto adj : G[u]) if(adj != p) DFS(adj, u, d + 1);
	fn[u] = T;
}

ll Blift(ll u, ll h){
	for(int i = 0; i < Log; i++) if(h >> i & 1) u = sp[u][i];
	return u;
}
ll LCA(ll u, ll v){
	if(dep[u] < dep[v]) swap(u, v);
	u = Blift(u, dep[u] - dep[v]);
	if(u == v) return u;
	for(int l = Log - 1; l >= 0; l--){
		if(sp[u][l] != sp[v][l]){
			u = sp[u][l];
			v = sp[v][l];
		}
	}
	return sp[u][0];
}
ll Dis(ll u, ll v){
	return dep[u] + dep[v] - 2*dep[LCA(u, v)]; //Dis(u, v);
}

ll ans[N], K[N], M[N];
bool CMP(ll i, ll j){
	return st[i] < st[j];
}
vector<ll> Tr[N];
vector<ll> Q;
ll po; 
void dfs(ll u){
	while(po < Q.size()){
		//debug(u);
		if(st[u] <= st[Q[po]] && st[Q[po]] < fn[u]){
			Tr[u].pb(Q[po]);
			Tr[Q[po]].pb(u);
			//cerr << "!! " <<  u << " " << Q[po] << '\n';
			po ++;
			dfs(Q[po - 1]);
		} else break;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n; 
	ll u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, 1);
	for(int l = 1; l < Log; l++) for(int i = 1; i <= n; i++) sp[i][l] = sp[sp[i][l - 1]][l - 1];
	ll q;
	cin >> q;
	
	set<pair<ll, pll>> st;

	ll k, m;
	for(int o = 0; o < q; o++){
		cin >> k >> m;
		Q.clear();
		for(int j = 0; j < k; j++) cin >> K[j] >> spd[j];
	
		for(int j = 0; j < m; j++) cin >> M[j];
		for(int j = 0; j < k; j++) Q.pb(K[j]);
		for(int j = 0; j < m; j++) Q.pb(M[j]);
		sort(all(Q), CMP);
		//debug(Q.size());
		//debug("TT");
		//for(auto x : Q) cerr << x << ' ' ;
			//cerr << '\n';
		
		for(int i = 0; i + 1 < k + m; i++){
			Q.pb(LCA(Q[i], Q[i + 1]));
			//debug(Q[i]);
			//debug(Q[i + 1]);
			assert(LCA(Q[i], Q[i + 1]));
		}
		sort(all(Q), CMP);
		Q.resize(unique(all(Q)) - Q.begin());
		//debug(Q.size());
		//for(auto x : Q) cerr << x << ' ' ;
			//cerr << '\n';
		//ll al = Q.size();
		for(auto x : Q) Tr[x].clear();
		for(auto x : Q) ans[x] = -1;
		po = 1;
		dfs(Q[0]);
		st.clear();
		for(int i = 0; i < k; i++){
			st.insert({0, {i, K[i]}});
		}
		while(st.size()){
			u = st.begin()->S.S;
			ll T = st.begin() -> S.F;

			st.erase(st.begin());
			if(ans[u] != -1){
				continue;
			}
			ans[u] = T;
			for(auto adj : Tr[u]){
				st.insert({(Dis(K[T], adj) + spd[T] - 1)/ spd[T], {T, adj}});
			}
		}
		for(int i = 0; i < m; i++) cout << ans[M[i]] + 1 << ' ';
			cout << '\n';
	}
	return 0;
}