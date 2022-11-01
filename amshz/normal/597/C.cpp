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
const int xn = 1e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, k, num[xn];
ll Seg[xm][xn * 4], dp[xm][xn], ans;

void Update(int id, int L, int R, int x, ll val, int ind){
	if (R - L == 1){
		Seg[ind][id] += val;
		return;
	}
	int Mid = (L + R) / 2;
	if (x < Mid) Update(id * 2, L, Mid, x, val, ind);
	else Update(id * 2 + 1, Mid, R, x, val, ind);
	Seg[ind][id] = Seg[ind][id * 2] + Seg[ind][id * 2 + 1];
}
ll Get(int id, int L, int R, int Ql, int Qr, int ind){
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return Seg[ind][id];
	int Mid = (L + R) / 2;
	return Get(id * 2, L, Mid, Ql, Qr, ind) + Get(id * 2 + 1, Mid, R, Ql, Qr, ind);
}

 
int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 0; i < n; i ++) cin >> num[i];
	for (int i = 0; i < n; i ++){
		for (int j = 0; j <= k; j ++){
			if (j == 0) dp[j][i] = 1;
			else dp[j][i] = Get(1, 0, xn, 1, num[i], j - 1);
			Update(1, 0, xn, num[i], dp[j][i], j);
			if (j == k) ans += dp[j][i];
		}
	}
	cout << ans << endl;
 	
	return 0;
}