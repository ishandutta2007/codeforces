// Zende bad Shoma nasime faghat !
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
const ll Log = 20;

int n, m, k;
int st[N], fn[N], sub[N], dep[N], T = 1;
vector<int> H[N], G[N];

void Sub(int u, int p){
	sub[u] = 1;
	for(auto adj : H[u]){
		if(adj == p) continue;
		Sub(adj, u);
		sub[u] += sub[adj];
	}
	sort(all(H[u]), [&](int i, int j){
		return sub[i] > sub[j];
	});
}

void Start(int u, int p, int d){
	st[u] = T ++;
	
	sub[st[u]] = 1;
	dep[st[u]] = d;

	for(auto adj : H[u]){
		if(adj == p) continue;
		Start(adj, u, d + 1);
		G[st[u]].pb(st[adj]);
		//cerr << "$ " << st[u] << ' ' << st[adj] << '\n';
	}
	fn[st[u]] = T;
}

int sp[N][Log];
void Prep(int u, int p){
	sp[u][0] = p;
	for(int i = 1; i < Log; i++)
		sp[u][i] = sp[sp[u][i - 1]][i - 1];
	for(auto adj : G[u])
		Prep(adj, u);
}

int Blift(int u, int h){
	for(int i = 0; i < Log; i++)
		if(h >> i & 1)
			u = sp[u][i];
	return u;
}

int LCA(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	v = Blift(v, dep[v] - dep[u]);
	if(u == v) return u;
	for(int lg = Log - 1; lg >= 0; lg --){
		if(sp[u][lg] != sp[v][lg]){
			u = sp[u][lg];
			v = sp[v][lg];
		}
	}
	return sp[u][0];
}

ll ans = 0;
int A[N], B[N], lc[N], ln[N];
vector<int> P[N];

int fen[N];
void Add(int idx, int d){
	//assert(idx > 0);
	for(; idx < N; idx += (idx & -idx))
		fen[idx] += d;
}
int Get(int idx){
	//assert(idx >= 0);
	int res = 0;
	for(; idx; idx -= (idx & -idx)){
		res += fen[idx];
	}
	return res;
}
void AddPath(int id, int d){
	Add(A[id], d);
	Add(B[id], d);
	
	Add(lc[id], -d);
	if(sp[lc[id]][0])
		Add(sp[lc[id]][0], -d);
}
int GetNode(int u){
	return Get(fn[u] - 1) - Get(u - 1);
}
int Find(int id, int K){
	if(K > ln[id]){
		//assert(false);
		return -1;
	}
	if(dep[A[id]] - dep[lc[id]] >= K) return Blift(A[id], K);
	return Blift(B[id], ln[id] - K);
}

map<pair<int, int>, int> mp;

void Solve(int u, bool keep){

	//cerr << u << ' ' << keep << '\n';

	int big = (G[u].empty() ? -1 : G[u][0]);
	//cerr << big << '\n';
	for(auto adj : G[u])
		if(adj != big)
			Solve(adj, false);
	if(big != -1) Solve(big, true);
	
	int v, sh;
	for(auto adj : G[u]){
		if(adj == big) continue;

		//cerr << "# " << adj << '\n'; 
		for(int i = adj; i < fn[adj]; i++){
			for(auto &id : P[i]){
				sh = k + (dep[i] - dep[u]);
				if(ln[id] < sh) continue;
				v = Find(id, (i == A[id] ? sh : ln[id] - sh));
				if(lc[id] < u) ans += GetNode(v);
			}
		}
		for(int i = adj; i < fn[adj]; i++){
			for(auto &id : P[i])
				AddPath(id, 1);
		}
	}

	for(auto &id : P[u]){
		//cerr << "A " << id << '\n';
		sh = k + (dep[u] - dep[u]);
		if(ln[id] >= sh){
			v = Find(id, (u == A[id] ? sh : ln[id] - sh));
			if(lc[id] < u) ans += GetNode(v);
		}
		AddPath(id, 1);
		//cerr << "AD " << id << '\n';
	
	}
	/*
	for(auto &id : P[u]){
		//cerr << "B " << id << ' ' << A[id] << ' ' << B[id] << ' ' << lc[id] << '\n';
		AddPath(id, 1);
		//cerr << "BD " << id << '\n';
	}
	*/
	if(!keep){
		//cerr << ":\\\n";
		for(int i = u; i < fn[u]; i++)
			for(auto &id : P[i])
				AddPath(id, -1);
	}
	//cerr << "! " << u << ' ' << ans << '\n';
}

int gd[N];

void Solve2(int u, bool keep){

	//cerr << u << ' ' << keep << '\n';

	int big = (G[u].empty() ? -1 : G[u][0]);
	//cerr << big << '\n';
	for(auto adj : G[u])
		if(adj != big)
			Solve2(adj, false);
	if(big != -1) Solve2(big, true);
	
	//int v, sh;
	pair<int, int> E;
	for(auto adj : G[u]){
		if(adj == big) continue;

		for(int i = adj; i < fn[adj]; i++){
			for(auto &id : P[i]){
				if(dep[u] <= k) continue;
				if(lc[id] == u) continue;
				if(dep[u] - dep[lc[id]] < k) continue;

				ans += Get(dep[u] - k);
				
				E.F = lc[id];
				
				if(dep[lc[id]] == min(dep[A[id]], dep[B[id]])) continue;
				if(A[id] == i) E.S = Blift(B[id], dep[B[id]] - dep[lc[id]] - 1);
				if(B[id] == i) E.S = Blift(A[id], dep[A[id]] - dep[lc[id]] - 1); 
				
				ans -= mp[E];
			}
		}
		for(int i = adj; i < fn[adj]; i++){
			for(auto &id : P[i]){
				Add(dep[lc[id]], 1);
				
				E.F = lc[id];
				
				if(dep[lc[id]] == min(dep[A[id]], dep[B[id]])) continue;
				if(A[id] == i) E.S = Blift(B[id], dep[B[id]] - dep[lc[id]] - 1);
				if(B[id] == i) E.S = Blift(A[id], dep[A[id]] - dep[lc[id]] - 1); 
				
				mp[E] ++;
			}
		}
	}

	for(auto &id : P[u]){
		//cerr << "A " << id << '\n';
		for(int i = 0; i <= 0; i++){

			if(dep[u] <= k) continue;
			if(lc[id] == u) continue;
			if(dep[u] - dep[lc[id]] < k) continue;

			ans += Get(dep[u] - k);

			E.F = lc[id];
				
			if(dep[lc[id]] == min(dep[A[id]], dep[B[id]])) continue;
			if(A[id] == u) E.S = Blift(B[id], dep[B[id]] - dep[lc[id]] - 1);
			if(B[id] == u) E.S = Blift(A[id], dep[A[id]] - dep[lc[id]] - 1); 
			
			//cerr << "% " << id << ' ' << E.F << ' ' << E.S << '\n';	
			ans -= mp[E];
		}


		Add(dep[lc[id]], 1);
		

		E.F = lc[id];
		
		if(dep[lc[id]] == min(dep[A[id]], dep[B[id]])) continue;
		if(A[id] == u) E.S = Blift(B[id], dep[B[id]] - dep[lc[id]] - 1);
		if(B[id] == u) E.S = Blift(A[id], dep[A[id]] - dep[lc[id]] - 1); 
		
		mp[E] ++;
		//cerr << "AD " << id << '\n';
	
	}
	/*
	for(auto &id : P[u]){
		//cerr << "B " << id << ' ' << A[id] << ' ' << B[id] << ' ' << lc[id] << '\n';
		AddPath(id, 1);
		//cerr << "BD " << id << '\n';
	}
	*/
	if(!keep){
		//cerr << ":\\\n";
		for(int i = u; i < fn[u]; i++)
			for(auto &id : P[i]){
				Add(dep[lc[id]], -1);
						
				E.F = lc[id];
				
				if(dep[lc[id]] == min(dep[A[id]], dep[B[id]])) continue;
				if(A[id] == i) E.S = Blift(B[id], dep[B[id]] - dep[lc[id]] - 1);
				if(B[id] == i) E.S = Blift(A[id], dep[A[id]] - dep[lc[id]] - 1); 
				
				mp[E] --;
			}
	}
	//cerr << "! " << u << ' ' << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		H[u].pb(v);
		H[v].pb(u);
	}
	Sub(1, 0);
	Start(1, 0, 1);
	Prep(1, 0);

	for(int i = 1; i <= m; i++){
		cin >> A[i] >> B[i];
		A[i] = st[A[i]];
		B[i] = st[B[i]];
		lc[i] = LCA(A[i], B[i]);
		ln[i] = dep[A[i]] + dep[B[i]] - 2 * dep[lc[i]];

		assert(min({dep[A[i]], dep[B[i]], dep[lc[i]]}) > 0);

		P[A[i]].pb(i);
		P[B[i]].pb(i);
		//cerr << "& " << A[i] << ' ' << B[i] << '\n';
	}
	//cerr << "Starting Solve\n";

	Solve2(1, false);
	//cerr << ans << '\n';
	//Solve2(1, false);
	Solve(1, true);

	cout << ans/2 << '\n';
	return 0;
}
/*
4 2 1
1 2
1 3
3 4
2 3
2 4

*/