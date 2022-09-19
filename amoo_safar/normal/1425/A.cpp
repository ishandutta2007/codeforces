// That's How much we have in common
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll solve(ll x){
	if(x <= 4){
		if(x == 1) return 1;
		if(x == 2) return 1;
		if(x == 3) return 2;
		return 3;
	}

	if(x & 1) return x - solve(x - 1);
	if(x % 4 == 0) return 1 + solve(x - 2);
	return x - solve(x >> 1);
}
ll dp[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*
	dp[1] = 1;
	for(int i = 2; i < N; i++){
		dp[i] = i - dp[i - 1];
		if(i % 2 == 0)
			dp[i] = max(dp[i], i - dp[i / 2]);
		if(i < 10) cout << i << " : " << dp[i] << ' ' << solve(i) << '\n';
		assert(dp[i] == solve(i));
	}
	*/
	//return 0;

	ll t;
	cin >> t;
	ll n;
	while(t --){
		cin >> n;
		cout << solve(n) << '\n';
	}
	return 0;
}