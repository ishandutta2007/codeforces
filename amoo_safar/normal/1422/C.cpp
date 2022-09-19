// I'll Crush you !
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

ll dp[N][3];
ll C[N][3];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;

	dp[0][0] = s[0] - '0';
	dp[0][1] = 0;
	C[0][0] = 1;
	C[0][1] = 1;

	for(int i = 1; i < (int) s.size(); i++){
		int d = s[i] - '0';
		dp[i][0] = dp[i - 1][0] * 10 + C[i - 1][0] * d;
		
		dp[i][1] = dp[i - 1][1] + dp[i - 1][0];

		dp[i][2] = dp[i - 1][2] * 10 + C[i - 1][2] * d  +  dp[i - 1][1] * 10 + C[i-1][1] * d;
	

		C[i][0] = C[i - 1][0];
		C[i][1] = C[i - 1][1] + C[i-1][0];
		C[i][2] = C[i - 1][2] + C[i-1][1];

		for(int j = 0; j < 3; j++) dp[i][j] %= Mod;

	}
	cout << (dp[s.size() - 1][1] + dp[s.size() - 1][2] ) % Mod<<'\n';
	return 0;
}