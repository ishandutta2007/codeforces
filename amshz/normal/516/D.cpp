# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll dist[2][xn], L[xn], R[xn], a[xn], t;
int n, X, Y, root, q, ans, ptr, fen[xn];
vector <pii> adj[xn], vec;

bool cmp(pii i, pii j){
	ll x = a[i.B];
	if (i.A) x = a[i.B] + t;
	ll y = a[j.B];
	if (j.A) y = a[j.B] + t;
	if (x != y) return x < y;
	return i.A < j.A;
}
void modify(int pos){ for (; pos < xn; pos += pos & -pos) ++ fen[pos];}
int get(int pos){
	int sum = 0;
	for (; pos > 0; pos -= pos & -pos) sum += fen[pos];
	return sum;
}
void check(){
	ans = 0;
	memset(fen, 0, sizeof fen);
	vec.clear();
	for (int i = 1; i <= n; ++ i){
		vec.push_back({0, i});
		vec.push_back({1, i});
	}
	sort(all(vec), cmp);
	for (pii x : vec){
		if (x.A) ans = max(ans, get(R[x.B]) - get(L[x.B] - 1));
		else modify(L[x.B]);
	}
	cout << ans << endl;
}
void DFS2(int v, int p = - 1){
	L[v] = R[v] = ++ ptr;
	for (pii u : adj[v]){
		if (u.A == p) continue;
		DFS2(u.A, v);
		R[v] = R[u.A];
	}
}
void DFS(int v, int ind, int p = - 1){
	for (pii u : adj[v]){
		if (u.A == p) continue;
		dist[ind][u.A] = dist[ind][v] + u.B;
		DFS(u.A, ind, v);
	}
}
 
int main(){
    InTheNameOfGod;
    
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	DFS(1, 0);
	X = 1;
	for (int i = 1; i <= n; ++ i) if (dist[0][i] > dist[0][X]) X = i;
	dist[0][X] = 0;
	DFS(X, 0);
	Y = 1;
	for (int i = 1; i <= n; ++ i) if (dist[0][i] > dist[0][Y]) Y = i;
	DFS(Y, 1);
	for (int i = 1; i <= n; ++ i) a[i] = max(dist[0][i], dist[1][i]);
	root = 1;
	for (int i = 1; i <= n; ++ i) if (a[i] < a[root]) root = i;
	DFS2(root);
	cin >> q;
	while (q --){
		cin >> t;
		check();
	}
 
    return 0;
}