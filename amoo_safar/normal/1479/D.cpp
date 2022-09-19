// vaziat meshki-ghermeze !
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 20;

vector<int> G[N], V[N];


int a[N];
ll x[N];

int sp[Log][N];
int st[N], fn[N], dep[N], T = 1;
void DFS(int u, int p, int d = 0){
	st[u] = T ++;
	sp[0][u] = p;
	dep[u] = d;
	for(auto adj : G[u]){
		if(adj == p) continue;
		DFS(adj, u, d + 1);
	}
	fn[u] = T;
}

int Blift(int u, int h){
	for(int i =0; i < Log; i++)
		if(h >> i & 1)
			u = sp[i][u];
	return u;
}
int LCA(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	// cerr << "! " << u << ' ' << v << '\n';
	u = Blift(u, dep[u] - dep[v]);
	if(u == v) return u;

	for(int i = Log - 1; i >= 0; i--){
		if(sp[i][u] != sp[i][v]){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}


ll fen[N];
void Add(int idx, ll d){
	for(; idx < N; idx += (idx & (-idx)))
		fen[idx] ^= d;
}
ll Get(int idx){
	ll res = 0;
	for(; idx; idx -= (idx & (-idx)))
		res ^= fen[idx];
	return res;
}

int lc[N], lb[N], rb[N], lq[N], rq[N], md[N];
int uu[N], vv[N];

ll val[N];
typedef pair<int, int> pii;

vector<pii> Ev[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	mt19937 Amoo(chrono::steady_clock::now().time_since_epoch().count());

	// cout << rng() << '\n';
	uniform_int_distribution<ll> shayan;
	// cout << shayan(rng) << '\n';
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		V[a[i]].pb(i);
	}
	for(int i = 1; i <= n; i++){
		x[i] = shayan(Amoo);
		// debug(x[i]);
	}

	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, 0);
	for(int l  = 1; l < Log; l++){
		for(int i = 1; i <= n; i++)
			sp[l][i] = sp[l - 1][sp[l - 1][i]];
	}

	for(int i = 0; i < q; i++){
		cin >> uu[i] >> vv[i] >> lq[i] >> rq[i];
		lc[i] = LCA(uu[i], vv[i]);
		// debug(lc[i]);
		lq[i] --;

		lb[i] = lq[i];
		rb[i] = rq[i] + 1;
	}

	for(int iter = 0; iter < Log; iter ++){
		memset(val, 0, sizeof val);
		memset(fen, 0, sizeof fen);
		for(int i = 0; i <= n+2; i++) Ev[i].clear();

		for(int j = 0; j < q; j++){
			md[j] = (lb[j] + rb[j]) >> 1;
			if(lq[j] < a[lc[j]] && a[lc[j]] <= md[j]){
				val[j] ^= x[a[lc[j]]];
			}
			Ev[lq[j]].pb({uu[j], j});
			Ev[lq[j]].pb({vv[j], j});
			Ev[md[j]].pb({uu[j], j});
			Ev[md[j]].pb({vv[j], j});
		}
		for(int i = 1; i <= n; i++){
			for(auto id : V[i]){
				Add(st[id], x[i]);
				Add(fn[id], x[i]);
			}
			for(auto el : Ev[i]){
				val[el.S] ^= Get(st[el.F]);
			}
		}
		for(int i = 0; i < q; i++){
			if(val[i]){
				rb[i] = md[i];
			} else lb[i] = md[i];
		}

	}

	for(int i = 0; i < q; i++){
		cout << (rb[i] == rq[i] + 1 ? -1 : rb[i]) << '\n';
	}
	return 0;
}