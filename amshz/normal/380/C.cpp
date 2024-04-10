# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> ppp;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e6 + 10;
const int xm = 3e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, qq, mn;
string a;
ppp Seg[xn * 4];

ppp Merge(ppp x, ppp y){
	ppp z;
	mn = min(x.B.A, y.B.B);
	z.A = x.A + y.A + mn;
	z.B.A = x.B.A - mn + y.B.A;
	z.B.B = x.B.B + y.B.B - mn;
	return z;
}
void Build(int id, int L, int R){
	if (R - L == 1){
		if (R > n) return;
		if (a[L] == '(') Seg[id].B.A = 1;
		else Seg[id].B.B = 1;
		return;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	Seg[id] = Merge(Seg[id * 2], Seg[id * 2 + 1]);
}
ppp Get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return {0, {0, 0}};
	if (Ql <= L && R <= Qr) return Seg[id];
	int Mid = (L + R) / 2;
	return Merge(Get(id * 2, L, Mid, Ql, Qr), Get(id * 2 + 1, Mid, R, Ql, Qr));
}
 
int main(){
	InTheNameOfGod;
	
	cin >> a;
	n = a.size();
	Build(1, 0, xn);
	cin >> qq;
	while (qq --){
		int l, r;
		cin >> l >> r;
		cout << Get(1, 0, xn, l - 1, r).A * 2 << endl;
	}
 	
	return 0;
}