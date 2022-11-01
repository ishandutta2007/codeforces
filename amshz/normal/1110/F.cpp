# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, ll> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 5e5 + 10;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, qq, p[xn], Root = 1, Right[xn], St[xn], S = 1;
ll Seg[xn * 4], Lazy[xn * 4], Dist[xn], ans[xn], Tot, W;
vector <pii> adj[xn];
vector <pair <pii, int> > Q[xn];
bool Mark[xn], Leaf[xn];

void Build(int id, int L, int R){
	if (R - L == 1){
		if (Leaf[L]) Seg[id] = Dist[L];
		else Seg[id] = INF;
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	Seg[id] = min(Seg[id * 2], Seg[id * 2 + 1]);
}
void Shift(int id, int L, int R){
	if (Lazy[id] == 0) return;
	if (Seg[id] != INF) Seg[id] += Lazy[id];
	if (R - L > 1){
		Lazy[id * 2] += Lazy[id];
		Lazy[id * 2 + 1] += Lazy[id];
	}
	Lazy[id] = 0;
}
void Update(int id, int L, int R, int Ql, int Qr, ll Val){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id] += Val;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr, Val);
	Update(id * 2 + 1, Mid, R, Ql, Qr, Val);
	Seg[id] = min(Seg[id * 2], Seg[id * 2 + 1]);
}
ll Get(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return INF;
	if (Ql <= L && R <= Qr) return Seg[id];
	int Mid = (L + R) / 2;
	return min(Get(id * 2, L, Mid, Ql, Qr), Get(id * 2 + 1, Mid, R, Ql, Qr));
}

void DFS2(int v){
	for (pair <pii, int> q : Q[v]) ans[q.B] = Get(1, 0, xn, q.A.A, q.A.B + 1) + Tot;
	for (pii u : adj[v]){
		Tot += u.B;
		Update(1, 0, xn, St[u.A], Right[u.A] + 1, - 2 * u.B);
		DFS2(u.A);
		Tot -= u.B;
		Update(1, 0, xn, St[u.A], Right[u.A] + 1, 2 * u.B);
	}
}
void DFS(int v){
	St[v] = S ++;
	Right[v] = St[v];
	for (pii u : adj[v]){
		Dist[u.A] = Dist[v] + u.B;
		DFS(u.A);
		Right[v] = Right[u.A];
	}
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> qq;
	for (int i = 1; i <= n; i ++) Leaf[i] = true;
	for (int i = 2; i <= n; i ++){
		cin >> p[i] >> W;
		Leaf[p[i]] = false;
		adj[p[i]].push_back({i, W});
	}
	DFS(Root);
	Build(1, 0, xn);
	for (int i = 1; i <= qq; i ++){
		int v, l, r;
		cin >> v >> l >> r;
		Q[v].push_back({{l, r}, i});
	}
	DFS2(Root);
	for (int i = 1; i <= qq; i ++) cout << ans[i] << endl;
	
	return 0;
}