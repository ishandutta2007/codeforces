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
const int xn = 1e2+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
string base2(ll a){
	string bin = "";
	while (a){
		if (a % 2) bin = '1' + bin;
		else bin = '0' + bin;
		a /= 2;
	}
	return bin;
}

ll l, r, dp[xn][2], m[xn], dp2[xn][2];
bool mark[xn];


void Calc(ll n){
	if (mark[n]) return;
	dp2[n][0] = 0;
	for (ll i = 1; i < n; i ++){
		if (n % i) continue;
		Calc(i);
		dp2[n][0] += dp2[i][1];
	}
	dp2[n][1] = m[n] - dp2[n][0];
	mark[n] = true;
}



ll Solve(ll n){
	ll ans = 0;
	string bin = base2(n);
	for (int i = 1; i < bin.size(); i ++) ans += dp[i][0];
	memset(mark, false, sizeof mark);
	memset(m, 127, sizeof m);
	memset(dp2, 0, sizeof dp2);
	for (int i = 1; i < bin.size(); i ++){
		if (bin.size() % i) continue;
		ll s = 0;
		for (int j = 0; j < i; j ++){
			if (bin[j] == '1') s += (1LL << (i - j - 1LL));
		}
		if (s < (1LL << (i - 1LL))){
			m[i] = 0;
			continue;
		}
		m[i] = s - (1LL << (i - 1LL));
		ll x = 0;
		for (int j = 0; j < bin.size(); j ++){
			int ind = j % i;
			if (bin[j % i] == '0') continue;
			x += (1LL << (bin.size() - j - 1LL));
		}
		m[i] += (x <= n);
	}
	Calc(bin.size());
	ans += dp2[bin.size()][0];
	return ans;
}




int main(){
	fast_io;
	
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= 60; i ++){
		for (int j = 1; j < i; j ++){
			if (i % j) continue;
			dp[i][0] += dp[j][1];
		}
		dp[i][1] = (1LL << (i - 1LL)) - dp[i][0];
	}
	
	cin >> l >> r;
	
	cout << Solve(r) - Solve(l - 1) << endl;
	
	
	return 0;
}