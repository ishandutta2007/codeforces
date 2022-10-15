#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print2(ar, n, m) for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define print(ar, n) for(int i = 0; i < n; i++) cout << ar[i] <<  " ";
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef map<int, int>::iterator mit;
const int MAX = 2e5;
const ld E = 1e-11;

int main() {

	sync;

	int n;
	cin >> n;

	int x[n + 1], h[n];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> h[i];

	x[n] = INT_MAX;

	int dp[n][2];
	ms(dp);
	dp[0][0] = 1;
	dp[0][1] = 1;

	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i - 1][0] + (x[i] - x[i - 1] > h[i] ? 1 : 0), dp[i - 1][1] + (x[i] - x[i - 1] > h[i] + h[i - 1] ? 1 : 0));
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		if(x[i + 1] - x[i] > h[i])
			dp[i][1]++;
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);

}