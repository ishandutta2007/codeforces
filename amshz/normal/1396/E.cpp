//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, sz[xn], rt, wc[xn], pt[xn], par[xn], H[xn];
ll k, sum, mn, mx;
vector <int> adj[xn];
vector <pii> vec[xn];
set <int> bach[xn], S[xn];
set <pii> st, szs;
bool mark[xn];

void plant(int v, int p = - 1){
	sz[v] = 1;
	for (int u : adj[v])
		if (u != p)
			plant(u, v), sz[v] += sz[u];
	mn += sz[v] % 2;
	mx += min(sz[v], n - sz[v]);
}
int find_centroid(int v, int p = - 1){
	for (int u : adj[v])
		if (u != p && n < sz[u] + sz[u])
			return find_centroid(u, v);
	return v;
}
void DFS(int v, int p = - 1){
	if (v != rt && !wc[v])
		wc[v] = v;
	if (v != rt)
		vec[wc[v]].push_back({- H[v], v});
	sum += H[v];
	sz[v] = 1;
	for (int u : adj[v]){
		if (u == p)
			continue;
		H[u] = H[v] + 1;
		wc[u] = wc[v];
		par[u] = v;
		DFS(u, v);
		bach[v].insert(u);
		sz[v] += sz[u];
	}
	if (p == rt){
		st.insert({- sz[v], v});
		sort(all(vec[v]));
	}
}

int main(){
	//fast_io;

	cin >> n >> k;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	plant(1);
	if (k % 2 != mn % 2 || k < mn || mx < k)
		kill("NO");
	rt = find_centroid(1);
	DFS(rt);
	k = (sum - k) / 2;
	cout << "YES" << endl;
	while (k){
		int c = st.begin() -> B;
		while (pt[c] < SZ(vec[c])){
			int v = vec[c][pt[c]].B;
			if (mark[v] || !SZ(bach[v]))
				++ pt[c];
			else
				break;
		}
		int v = vec[c][pt[c]].B;
		if (k < H[v])
			break;
		st.erase({- sz[c], c});
		sz[c] -= 2;
		st.insert({- sz[c], c});
		k -= H[v];
		if (SZ(bach[v]) == 1){
			int u = *bach[v].begin();
			mark[v] = true;
			mark[u] = true;
			bach[v].erase(u);
			bach[par[v]].erase(v);
			cout << v << sep << u << endl;
		}
		else{
			int u = *bach[v].begin();
			bach[v].erase(u);
			int w = *bach[v].begin();
			bach[v].erase(w);
			mark[u] = mark[w] = true;
			cout << u << sep << w << endl;
		}
	}
	if (k){
		int c = st.begin() -> B;
		while (pt[c] < SZ(vec[c])){
			int v = vec[c][pt[c]].B;
			if (mark[v] || !SZ(bach[v]))
				++ pt[c];
			else
				break;
		}
		int v = vec[c][pt[c]].B;
		while (H[v] != k)
			v = par[v];
		int u = *bach[v].begin();
		bach[v].erase(u);
		bach[par[v]].erase(v);
		mark[v] = mark[u] = true;
		cout << v << sep << u << endl;
	}
	S[0].insert(rt);
	szs.insert({- 1, 0});
	for (int v = 1; v <= n; ++ v){
		if (v != wc[v])
			continue;
		for (pii u : vec[v])
			if (!mark[u.B])
				S[v].insert(u.B);
		if (SZ(S[v]))
			szs.insert({- SZ(S[v]), v});
	}
	while (SZ(szs)){
		int x = szs.begin() -> B;
		szs.erase(szs.begin());
		int y = szs.begin() -> B;
		szs.erase(szs.begin());
		int v = *S[x].begin();
		S[x].erase(v);
		int u = *S[y].begin();
		S[y].erase(u);
		cout << v << sep << u << endl;
		if (SZ(S[x]))
			szs.insert({- SZ(S[x]), x});
		if (SZ(S[y]))
			szs.insert({- SZ(S[y]), y});
	}

	return 0;
}