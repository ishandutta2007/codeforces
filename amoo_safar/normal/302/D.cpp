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
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll x[N], y[N], a[N];
ll dp[N];

ll dis(ll i, ll j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, d;
	cin >> n >> d;
	for(int i = 1; i < n - 1; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	memset(dp, 31, sizeof dp);
	dp[n - 1] = 0;
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j) dp[i] = min(dp[i], dp[j] + d * dis(i, j) - a[i]);
			}
		}
	}
	//cout << dp[1] << '\n';
	//cout << dp[2] << '\n';
	cout << dp[0] << '\n';
	return 0;
}
/*
6 1000
1000 1000 1000 1000
0 0
0 1
1 1
2 1
3 1
3 0
*/