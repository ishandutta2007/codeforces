#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
//#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
const int MAX = 1e5;
const ld E = 1e-9;

int main(){

	int n, m, b, mod;
	cin >> n >> m >> b >> mod;

	int dp[m + 1][b + 1];
	ms(dp);
	dp[0][0] = 1 % mod;

	while(n--){
		int x;
		cin >> x;
		for(int i = 1; i <= m; i++)
			for(int j = x; j <= b; j++)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
	}

	int ans = 0;
	for(int i = 0; i <= b; i++)
		ans = (ans + dp[m][i]) % mod;

	cout << ans;




}