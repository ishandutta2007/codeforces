# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, pii> ppp;
 
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
 
int n, qq;
pii Seg[xn * 4], dp[xn * 4];
string a;
bool Lazy[xn * 4];

void Build(int id, int L, int R){
	if (R - L == 1){
		if (R > n) return;
		Seg[id].B = (a[L] == '7');
		Seg[id].A = 1 - Seg[id].B;
		dp[id].A = dp[id].B = 1;
		return ;
	}
	int Mid = (L + R) / 2;
	Build(id * 2, L, Mid);
	Build(id * 2 + 1, Mid, R);
	dp[id].A = max(dp[id * 2].A + Seg[id * 2 + 1].B, Seg[id * 2].A + dp[id * 2 + 1].A);
	dp[id].B = max(dp[id * 2].B + Seg[id * 2 + 1].A, Seg[id * 2].B + dp[id * 2 + 1].B);
	Seg[id].A = Seg[id * 2].A + Seg[id * 2 + 1].A;
	Seg[id].B = Seg[id * 2].B + Seg[id * 2 + 1].B;
}
void Shift(int id, int L, int R){
	if (!Lazy[id]) return;
	swap(Seg[id].A, Seg[id].B);
	swap(dp[id].A, dp[id].B);
	if (R - L > 1){
		Lazy[id * 2] = !Lazy[id * 2];
		Lazy[id * 2 + 1] = !Lazy[id * 2 + 1];
	}
	Lazy[id] = false;
}
void Update(int id, int L, int R, int Ql, int Qr){
	Shift(id, L, R);
	if (Qr <= L || R <= Ql) return;
	if (Ql <= L && R <= Qr){
		Lazy[id] = true;
		Shift(id, L, R);
		return;
	}
	int Mid = (L + R) / 2;
	Update(id * 2, L, Mid, Ql, Qr);
	Update(id * 2 + 1, Mid, R, Ql, Qr);
	dp[id].A = max(dp[id * 2].A + Seg[id * 2 + 1].B, Seg[id * 2].A + dp[id * 2 + 1].A);
	dp[id].B = max(dp[id * 2].B + Seg[id * 2 + 1].A, Seg[id * 2].B + dp[id * 2 + 1].B);
	Seg[id].A = Seg[id * 2].A + Seg[id * 2 + 1].A;
	Seg[id].B = Seg[id * 2].B + Seg[id * 2 + 1].B;
}
void Get(){
	Shift(1, 0, xn);
	cout << dp[1].A << endl;
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> qq >> a;
	Build(1, 0, xn);
	while (qq --){
		string s;
		cin >> s;
		if (s[0] == 's'){
			int l, r;
			cin >> l >> r;
			l --;
			Update(1, 0, xn, l, r);
		}
		else Get();
	}
 	
	return 0;
}