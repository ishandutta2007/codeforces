# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e3 + 10;
const int xm = 3e5 + 10;
const int xlg = 2e1 + 10;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) { return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
	



int n, m, k;
pll A[xn];
ll dp[xn][xlg], Fact[xm], inv[xm], Bat, ans, Tot, T, B[xlg];
bool flag;


bool cmp(pii i, pii j){
	return i.F + i.S < j.F + j.S;
}
ll zarb(ll a, ll b){ return (a * b + 10 * md) % md;}
ll C(ll a, ll b){
	if (b > a || b < 0) return 0;
	return zarb(Fact[a], zarb(inv[b], inv[a - b]));
}


int main(){
	//fast_io;
	
	
	cin >> n >> m >> k >> Bat;
	for (int i = 0; i < k; i ++) cin >> A[i].F >> A[i].S;
	
	sort(A, A + k, cmp);
	
	Fact[0] = 1;
	for (ll i = 1; i <= 3e5; i ++) Fact[i] = (Fact[i - 1] * i + 10 * md) % md;
	for (int i = 0; i <= 3e5; i ++) inv[i] = power(Fact[i], md - 2);
	
	if (A[k - 1].F == n && A[k - 1].S == m) flag = true;
	else A[k] = {n, m}, k ++;
	
	Tot = C(n + m - 2, n - 1);
	T = power(Tot, md - 2);
	
	
	for (int i = 0; i < k; i ++){
		ll x = A[i].F, y = A[i].S;
		for (int j = 1; j <= 21; j ++){
			dp[i][j] = C(x + y - 2, x - 1);
			for (int p = 0; p < i; p ++){
				ll x2 = A[p].F, y2 = A[p].S;
				if (x + y == x2 + y2) continue;
				ll Bad = dp[p][j];
				Bad = zarb(Bad, C(x + y - x2 - y2, x - x2));
				dp[i][j] = (dp[i][j] - Bad + 10 * md) % md;
			}
			B[j] = dp[i][j] - dp[i][j - 1];
			B[j] = (B[j] + 10 * md) % md;
		}
		for (int j = 1; j <= 21; j ++) dp[i][j] = B[j];
	}
	for (int i = 0; i <= 20; i ++){
		ll s = 1;
		if (flag) s = dp[k - 1][i];
		else s = dp[k - 1][i + 1];
		ans = (ans + zarb(s, Bat) + 10 * md) % md;
		Tot = (Tot - s + 10 * md) % md;
		Bat = (Bat + 1) / 2;
	}
	
	ans = (ans + Tot + 10 * md) % md;
	
	cout << zarb(ans, T) << endl;
	
	
	return 0;
}