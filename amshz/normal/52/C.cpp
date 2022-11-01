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
const int xn = 2e5 + 10;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}

int qq, n, l, r;
ll seg[xn * 4], lazy[xn * 4], num[xn], x;
char d;

void Build(int id, int L, int R){
	if (R - L == 1){
		seg[id] = num[L];
		return;
	}
	int Mid = (L + R) / 2;
	Build(id*2, L, Mid);
	Build(id*2 + 1, Mid, R);
	seg[id] = min(seg[id*2], seg[id*2 + 1]);
}
void Shift(int id, int L, int R){
	if (lazy[id] == 0) return;
	seg[id] += lazy[id];
	if (R - L == 1){
		lazy[id] = 0;
		return;
	}
	lazy[id * 2] += lazy[id];
	lazy[id * 2 + 1] += lazy[id];
	lazy[id] = 0;
}
void Update(int id, int L, int R, int Ql, int Qr, ll Val){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		lazy[id] += Val;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr, Val);
	Update(id * 2 + 1, Mid, R, Ql, Qr, Val);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
ll Get(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return INF;
	if (Ql <= L && R <= Qr) return seg[id];
	int Mid = (L + R) / 2;
	return min(Get(id * 2, L, Mid, Ql, Qr), Get(id * 2 + 1, Mid, R, Ql, Qr));
}


int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%lld", num + i);
	Build(1, 0, xn);
	scanf("%d", &qq);
	while (qq --){
		scanf("%d %d", &l, &r);
		d = getchar();
		if (d == '\n'){
			if (r < l) cout << min(Get(1, 0, xn, 0, r + 1), Get(1, 0, xn, l, n)) << endl;
			else cout << Get(1, 0, xn, l, r + 1) << endl;
		}
		else{
			scanf("%lld", &x);
			if (r < l) Update(1, 0, xn, 0, r + 1, x), Update(1, 0, xn, l, n, x);
			else Update(1, 0, xn, l, r + 1, x);
		}
	}
 
	return 0;
}