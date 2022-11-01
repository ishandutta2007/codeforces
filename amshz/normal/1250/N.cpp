# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

struct ppp{ll Tavan[6] = {0, 0, 0, 0, 0, 0};};

ll n, qq, Lazy[xn * 4], num[xn], fact[xn], inv[xn], part[6][xn], X, C[10][10], pw[xn][6];
ppp Seg[xn * 4], Tohi;


ppp merge(ppp a, ppp b, ll x){
	ppp res;
	if (x <= 0) return b;
	for (ll i = 0; i <= 5; ++ i){
		res.Tavan[i] = a.Tavan[i];
		for (ll j = 0; j <= i; ++ j){
			X = (C[j][i] * pw[x][i - j] + md) % md;
			X = (X * b.Tavan[j] + md) % md;
			res.Tavan[i] = (res.Tavan[i] + X) % md;
		}
	}
	return res;
}
void Build(int id, int L, int R){
	Lazy[id] = -1;
	if (R - L == 1){
		for (int i = 0; i <= 5; ++ i) Seg[id].Tavan[i] = num[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	Seg[id] = merge(Seg[id * 2], Seg[id * 2 + 1], Mid - L);
}
void Shift(int id, int L, int R){
	if (Lazy[id] == -1) return;
	for (int i = 0; i <= 5; ++ i) Seg[id].Tavan[i] = (Lazy[id] * part[i][R - L]) % md;
	if (R - L > 1) Lazy[id * 2] = Lazy[id * 2 + 1] = Lazy[id];
	Lazy[id] = -1;
}
void Update(int id, int L, int R, int Ql, int Qr, ll val){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id] = val;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2, l = max(L, Ql);
	Update(id * 2, L, Mid, Ql, Qr, val);
	Update(id * 2 + 1, Mid, R, Ql, Qr, val);
	Seg[id] = merge(Seg[id * 2], Seg[id * 2 + 1], Mid - L);
}
ppp GET(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return Tohi;
	if (Ql <= L && R <= Qr) return Seg[id];
	int Mid = (L + R) / 2, l = max(L, Ql);
	return merge(GET(id * 2, L, Mid, Ql, Qr), GET(id * 2 + 1, Mid, R, Ql, Qr), Mid - l);
}

int main(){
	InTheNameOfGod;
	
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= 10; ++ i) fact[i] = zarb(fact[i - 1], i), inv[i] = power(fact[i], md - 2);
	for (ll i = 0; i <= 5; ++ i)
		for (ll j = 1; j < xn; ++ j)
			part[i][j] = jaam(part[i][j - 1], power(j, i));
	for (ll i = 0; i <= 5; ++ i) for (ll j = 0; j <= i; ++ j) C[j][i] = (fact[i] * ((inv[j] * inv[i - j] + md) % md)) % md;
	for (ll i = 0; i <= 5; ++ i) for (ll j = 0; j < xn; ++ j) pw[j][i] = power(j, i);
	cin >> n >> qq;
	for (int i = 1; i <= n; ++ i) cin >> num[i];
	char c;
	ll l, r, y;
	Build(1, 0, xn);
	while (qq --){
		cin >> c >> l >> r >> y;
		if (c == '?') cout << GET(1, 0, xn, l, r + 1).Tavan[y] << endl;
		else Update(1, 0, xn, l, r + 1, y);
	}
	return 0;
}