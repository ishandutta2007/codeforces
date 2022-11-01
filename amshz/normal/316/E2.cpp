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
 
const ll md = 1e9;
const int xn = 2e5 + 10;
const int xm = 8e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, qq, t;
ll num[xn], Fib[xn], Lazy[xn * 4], part[xn];
pii Seg[xn * 4];

ll F(ll a, ll b, int ind){
	if (ind == 0) return a;
	if (ind == 1) return b;
	return ((b * Fib[ind - 1]) % md + (a * Fib[ind - 2]) % md) % md;
}
void Build(int id, int L, int R){
	if (R - L == 1){
		Seg[id].A = Seg[id].B = num[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	Seg[id].A = (Seg[id * 2].A + F(Seg[id * 2 + 1].A, Seg[id * 2 + 1].B, Mid - L)) % md;
	Seg[id].B = (Seg[id * 2].B + F(Seg[id * 2 + 1].A, Seg[id * 2 + 1].B, Mid + 1 - L)) % md;
}
void Shift(int id, int L, int R){
	if (Lazy[id] == 0) return;
	Seg[id].A = (Seg[id].A + (part[R - L - 1] * Lazy[id]) % md) % md;
	Seg[id].B = (Seg[id].B + (((part[R - L] - 1 + md) % md) * Lazy[id]) % md) % md;
	if (R - L > 1){
		Lazy[id * 2] = (Lazy[id * 2] + Lazy[id]) % md;
		Lazy[id * 2 + 1] = (Lazy[id * 2 + 1] + Lazy[id]) % md;
	}
	Lazy[id] = 0;
}
void Update(int id, int L, int R, int Ql, int Qr, ll x){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id] = (Lazy[id] + x + md) % md;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr, x);
	Update(id * 2 + 1, Mid, R, Ql, Qr, x);
	Seg[id].A = (Seg[id * 2].A + F(Seg[id * 2 + 1].A, Seg[id * 2 + 1].B, Mid - L)) % md;
	Seg[id].B = (Seg[id * 2].B + F(Seg[id * 2 + 1].A, Seg[id * 2 + 1].B, Mid + 1 - L)) % md;
}
ll Get(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return F(Seg[id].A, Seg[id].B, L - Ql);
	int Mid = (L + R) / 2;
	return (Get(id * 2, L, Mid, Ql, Qr) + Get(id * 2 + 1, Mid, R, Ql, Qr)) % md;
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> qq;
	for (int i = 0; i < n; i ++) cin >> num[i];
	Fib[0] = Fib[1] = 1;
	part[0] = 1, part[1] = 2;
	for (int i = 2; i < xn; i ++) Fib[i] = (Fib[i - 1] + Fib[i - 2]) % md, part[i] = (part[i - 1] + Fib[i]) % md;
	Build(1, 0, xn);
 	while (qq --){
 		cin >> t;
 		if (t == 1){
 			int x;
 			ll y;
 			cin >> x >> y;
 			y = (y - Get(1, 0, xn, x - 1, x) + md) % md;
 			Update(1, 0, xn, x - 1, x, y);
		}
		if (t == 2){
			int l, r;
			cin >> l >> r;
			cout << Get(1, 0, xn, l - 1, r) << endl;
		}
		if (t == 3){
			int l, r;
			ll x;
			cin >> l >> r >> x;
			Update(1, 0, xn, l - 1, r, x);
		}
	 }
 	
	return 0;
}