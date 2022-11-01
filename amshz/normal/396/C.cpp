# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 3e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, qq, St[xn], S, Right[xn], num[xn], H[xn], Left[xn * 4];
vector <int> adj[xn];
ll ans;
pair <ll, pii> Lazy[xn * 4];

void DFS(int v){
	St[v] = S;
	num[S] = v;
	Right[v] = S;
	S ++;
	for (int u : adj[v]){
		H[u] = H[v] + 1;
		DFS(u);
		Right[v] = Right[u];
	}
}

void Update(int id, int L, int R, int Ql, int Qr, ll x, ll k){
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id].A = (Lazy[id].A + x + 100 * md) % md;
		Lazy[id].B.A = (Lazy[id].B.A + k * (H[num[L]] - H[num[Ql]]) % md + 100 * md) % md;
		Lazy[id].B.B = (Lazy[id].B.B + k + 100 * md) % md;
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr, x, k);
	Update(id * 2 + 1, Mid, R, Ql, Qr, x, k);
}
void GET(int id, int L, int R, int ind){
	if (L > ind || R <= ind) return;
	ans = (ans + Lazy[id].A + 100 * md) % md;
	ans = (ans - Lazy[id].B.A - ((H[num[ind]] - H[num[L]]) * Lazy[id].B.B + 100 * md) % md + 100 * md) % md;
	if (R - L == 1) return;
	int Mid = (L + R) / 2;
	if (ind < Mid) GET(id * 2, L, Mid, ind);
	else GET(id * 2 + 1, Mid, R, ind);
}


int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 2; i <= n; i ++){
		int v;
		cin >> v;
		adj[v].push_back(i);
	}
	DFS(1);
	cin >> qq;
	while (qq --){
		int t;
		cin >> t;
		if (t == 1){
			ll v, x, k;
			cin >> v >> x >> k;
			Update(1, 0, xn, St[v], Right[v] + 1, x, k);
		}
		else{
			int v;
			cin >> v;
			ans = 0;
			GET(1, 0, xn, St[v]);
			cout << ans << endl;
		}
	}
	
	
	return 0;
}