// nemibinam invara kasi mesle khodemono !
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
const int N = 5e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ll dp[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	str S, T;
	cin >> S >> T;


	ll ans = 0;
	for(int i = 0; i<=n; i++){
		for(int j = 0; j <= m; j++){
			if(i > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
			if(j > 0)
				dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
			if(i > 0 && j > 0 && S[i - 1] == T[j - 1])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
			ans = max(ans, dp[i][j]);
		}
	}


	cout << ans << '\n';
	return 0;
}