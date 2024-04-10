# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e7 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}
ll menha(ll a, ll b){
	return (a - b + 10 * md) % md;
}


ll x, y;
map <int, ll> dp;
map <int, bool> Mark;


void Solve(ll n){
	if (Mark[n]) return;
	dp[n] = power(2, n - 1);
	set <ll> st;
	for (int i = 1; i <= sqrt(n); i ++){
		if (n % i == 0) st.insert(i), st.insert(n / i);
	}
	st.erase(n);
	for (ll j : st){
		Solve(j);
		dp[n] = menha(dp[n], dp[j]);
	}
	Mark[n] = true;
}

 
 
int main(){
	fast_io;
	
	
	cin >> x >> y;
	if (y % x){
		cout << 0 << endl;
		return 0;
	}
	
	Solve(y / x);
	
	cout << dp[y / x] << endl;
	
	
	
	return 0;
}