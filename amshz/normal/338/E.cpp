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
const int xn = 2e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, len, h, part[xn], num[xn], b[xn], a[xn], Seg[xn * 4], Lazy[xn * 4], ans;

void Build(int id, int L, int R){
	if (R - L == 1){
		if (L >= 1 && L <= len) Seg[id] = -L;
		else Seg[id] = inf; 
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	Seg[id] = min(Seg[id * 2], Seg[id * 2 + 1]);
}
void Shift(int id, int L, int R){
	if (Lazy[id] == 0) return;
	Seg[id] += Lazy[id];
	if (R - L > 1){
		Lazy[id * 2] += Lazy[id];
		Lazy[id * 2 + 1] += Lazy[id];
	}
	Lazy[id] = 0;
}
void Update(int id, int L, int R, int Ql, int Qr, int val){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id] += val;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr, val);
	Update(id * 2 + 1, Mid, R, Ql, Qr, val);
	Seg[id] = min(Seg[id * 2], Seg[id * 2 + 1]);
}
int GET(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return inf;
	if (Ql <= L && R <= Qr) return Seg[id];
	int Mid = (L + R) / 2;
	return min(GET(id * 2, L, Mid, Ql, Qr), GET(id * 2 + 1, Mid, R, Ql, Qr));
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> len >> h;
	for (int i = 1; i <= len; ++ i) cin >> b[i];
	for (int i = 1; i <= n; ++ i) cin >> num[i];
	sort(b + 1, b + len + 1);
	for (int i = 1; i <= n; ++ i){
		int L = 0, R = len + 1, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (num[i] + b[Mid] >= h) R = Mid;
			else L = Mid;
		}
		a[i] = R;
	}
	Build(1, 0, xn);
	for (int i = 1; i <= len; ++ i) Update(1, 0, xn, a[i], len + 1, 1);
	ans += (GET(1, 0, xn, 1, len + 1) >= 0);
	for (int i = len + 1; i <= n; ++ i){
		Update(1, 0, xn, a[i - len], len + 1, -1);
		Update(1, 0, xn, a[i], len + 1, 1);
		ans += (GET(1, 0, xn, 1, len + 1) >= 0);
	}
	cout << ans << endl;
	
	return 0;
}