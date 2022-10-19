#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll n , x[MAXN] , y[MAXN] , s[MAXN] , match[MAXN] , dp[MAXN] , ps[MAXN];
vector<int> compress = {0};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] >> y[i] >> s[i];
		compress.push_back(x[i]);
		compress.push_back(y[i]);
	}
	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	for(int i = 0 ; i < n ; i++){
		x[i] = lower_bound(all(compress) , x[i]) - compress.begin();
		y[i] = lower_bound(all(compress) , y[i]) - compress.begin();
		match[x[i]] = match[y[i]] = y[i];
	}
	for(int i = 1 ; i <= n + n ; i++){
		dp[i] = (ps[i - 1] + MOD - ps[match[i] - 1] + compress[i] - compress[match[i]]) % MOD;
		ps[i] = (ps[i - 1] + dp[i]) % MOD;
	//	cout << i << sep << dp[i] << endl;
	}
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(s[i]){
			ans = (ans + dp[x[i]]) % MOD;
		}
	}
	cout << (ans + compress.back() + 1) % MOD << endl;

    return 0;
}
/*

*/