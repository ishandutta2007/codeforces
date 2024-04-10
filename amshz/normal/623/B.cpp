# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e6 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
int n;
ll A[xn], a, b, ans = inf, dp[xn], ps[xn][2], mn;
vector <ll> Primes;
bool p[xn];
 
 
void Solve(ll x){
	Primes.clear();
	ll y = x;
	for (ll i = 2; i <= 1e5; i ++){
		if (y < i) break;
		if (p[i]) continue;
		if (y % i == 0) Primes.push_back(i);
		while (y % i == 0) y /= i;
	}
	if (y > 1) Primes.push_back(y);
	
	for (ll k : Primes){
		memset(ps, 0, sizeof ps);
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i ++){
			if (i) ps[i][0] = ps[i - 1][0];
			if (A[i] % k == 0 || ps[i][0] == inf) continue;
			if ((A[i] + 1) % k == 0 || (A[i] - 1) % k == 0) ps[i][0] += b;
			else ps[i][0] = inf;
		}
		for (int i = n - 1; i >= 0; i --){
			ps[i][1] = ps[i + 1][1];
			if (A[i] % k == 0 || ps[i][1] == inf) continue;
			if ((A[i] + 1) % k == 0 || (A[i] - 1) % k == 0) ps[i][1] += b;
			else ps[i][1] = inf;
		}
		
		dp[0] = a;
		for (int i = 1; i < n; i ++)
			dp[i] = min(dp[i - 1], ps[i - 1][0]) + a;
		
		mn = ps[0][1];
		for (int i = 0; i < n; i ++) 
			ans = min(ans, dp[i] + ps[i + 1][1]);
		ans = min(ans, ps[0][1]);
	}
}
 
 
 
int main(){
	fast_io;
	
	cin >> n >> a >> b;
	for (int i = 0; i < n; i ++) cin >> A[i];
	
	for (int i = 2; i <= 1e4; i ++){
		if (p[i]) continue;
		for (int j = i + i; j <= 1e4; j ++) p[j] = true;
	}
	
	Solve(A[0]);
	Solve(A[0] + 1);
	Solve(A[0] - 1);
	
	reverse(A, A + n);
	
	Solve(A[0]);
	Solve(A[0] + 1);
	Solve(A[0] - 1);
	
	cout << ans << endl;
	
	
	return 0;
}