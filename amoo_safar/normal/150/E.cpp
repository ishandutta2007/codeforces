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
const int N = 131072;
const int Inf = 1e6;
const ll Log = 30;

int ans = -1, U = 1;
int n, lp, rp;
vector< pair<int, int> > G[N];
vector<int> V;

int seg[N << 1];
void Build(int id, int L = 0, int R = N){
	if(seg[id] == -Inf) return ;
	seg[id] = -Inf;
	if(L + 1 == R) return ;
	int mid = (L + R) >> 1;
	Build(id << 1, L, mid);
	Build(id << 1 | 1, mid, R);
}
int Get(int l, int r){
	int res = -Inf;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = max(res, seg[l++]);
		if (r & 1)
			res = max(seg[--r], res);
	}
	return res;
}
void Change(int idx, int v){
	idx += N;
	while(idx){
		seg[idx] = max(seg[idx], v);
		idx >>= 1;
	}
}

int mk[N], sub[N], dep[N], par[N], wp[N], sm[N];
int DFS(int u, int p, int d){
	sub[u] = 1;
	dep[u] = d;
	par[u] = p;
	for(auto [adj, w] : G[u]){
		if(mk[adj] || adj == p) continue;
		V.pb(adj);
		wp[adj] = w;
		sub[u] += DFS(adj, u, d + 1);
	}
	return sub[u];
}

void Solve(int u){
	int sz = DFS(u, -1, 0);
	
	bool flg = false;
	while(!flg){
		flg = true;
		for(auto [adj, w] : G[u]){
			if(!mk[adj] && sub[adj] < sub[u] && 2 * sub[adj] >= sz){
				u = adj;
				flg = false;
				break;
			}
		}
	}
	mk[u] = 1;
	V.clear();
	DFS(u, -1, 0);

	int L = 0, R = 1e9 + 1, mid;
	while(L + 1 < R){
		mid = (L + R) >> 1;
		sm[u] = 0;
		for(auto adj : V)
			sm[adj] = sm[par[adj]] + (wp[adj] >= mid ? 1 : -1);
		Build(1);
		Change(0, 0);

		flg = false;
		int la = 0, adj;
		for(int i = 0; i < (int)V.size(); i++){
			adj = V[i];
			if(dep[adj] == 1){
				for(int j = la; j < i; j++) Change(dep[V[j]], sm[V[j]]);
				la = i;
			}
			if(dep[adj] > rp) continue;
			if(sm[adj] + Get(max(0, lp - dep[adj]), rp - dep[adj] + 1) >= 0){
				flg = true;
				if(mid > ans){
					ans = mid;
					U = adj;
				}
			}
		}
		if(flg) L = mid;
		else R = mid;
	}
	for(auto [adj, w] : G[u]) if(!mk[adj]) Solve(adj);
}

void DFS2(int u, int p, int ms, int d){
	if(lp <= d && d <= rp && 0 <= ms) {
		cout << U << ' ' << u << '\n';
		exit(0);
	}
	for(auto [adj, w] : G[u]){
		if(adj != p)
			DFS2(adj, u, ms + (w >= ans ? 1 : -1), d + 1);
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> lp >> rp;
	int u, v, c;
	for(int i = 1; i < n; i++){
		cin >> u >> v >> c;
		G[u].pb({v, c});
		G[v].pb({u, c});
	}
	Solve(1);
	DFS2(U, -1, 0, 0);
	return 0;
}