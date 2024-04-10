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
 
const ll md = 1e9 + 9;
const int xn = 3e5 + 5;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}

int n, qq, t, l, r;
ll num[xn], seg[xn * 4], Fib[xn];
pii X[xn], Y[xn], Lazy[xn * 4];

ll F(pii a, int ind){ return ((a.A * X[ind].A) % md + (a.B * X[ind].B) % md) % md;}
ll Sum(pii a, int ind){ return ((a.A * Y[ind].A) % md + (a.B * Y[ind].B) % md) % md;}

void Build(int id, int L, int R){
	if (R - L == 1){
		seg[id] = num[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % md;
}
void Shift(int id, int L, int R){
	if (Lazy[id].A == 0 && Lazy[id].B == 0) return;
	seg[id] = (seg[id] + Sum(Lazy[id], R - L - 1)) % md;
	int Mid = (L + R) / 2;
	if (R - L > 1){
		Lazy[id * 2].A = (Lazy[id * 2].A + Lazy[id].A) % md;
		if (L + 1 < Mid) Lazy[id * 2].B = (Lazy[id * 2].B + Lazy[id].B) % md;
		Lazy[id * 2 + 1].A = (Lazy[id * 2 + 1].A + F(Lazy[id], Mid - L)) % md;
		if (Mid + 1 < R) Lazy[id * 2 + 1].B = (Lazy[id * 2 + 1].B + F(Lazy[id], Mid - L + 1)) % md;
	}
	Lazy[id].A = Lazy[id].B = 0;
}
void Update(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id].A = (Lazy[id].A + Fib[L - Ql]) % md;
		if (R - L > 1) Lazy[id].B = (Lazy[id].B + Fib[L - Ql + 1]) % md;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr);
	Update(id * 2 + 1, Mid, R, Ql, Qr);
	seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % md;
}
ll Get(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return (Get(id * 2, L, Mid, Ql, Qr) + Get(id * 2 + 1, Mid, R, Ql, Qr)) % md;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> qq;
	for (int i = 0; i < n; i ++) cin >> num[i];
	X[0] = Y[0] = {1, 0};
	X[1] = {0, 1}, Y[1] = {1, 1};
	for (ll i = 2; i < xn; i ++){
		X[i].A = (X[i - 1].A + X[i - 2].A) % md;
		X[i].B = (X[i - 1].B + X[i - 2].B) % md;
		Y[i].A = (Y[i - 1].A + X[i].A) % md;
		Y[i].B = (Y[i - 1].B + X[i].B) % md;
	}
	Fib[0] = Fib[1] = 1;
	for (int i = 2; i < xn; i ++) Fib[i] = (Fib[i - 1] + Fib[i - 2]) % md;
	
	Build(1, 0, xn);
	while (qq --){
		cin >> t >> l >> r;
		if (t == 1) Update(1, 0, xn, l - 1, r);
		else cout << Get(1, 0, xn, l - 1, r) << endl; 
	}
 
	return 0;
}