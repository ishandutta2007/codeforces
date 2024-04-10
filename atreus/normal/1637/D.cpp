#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 10;
const ll mod = 998244353;

int a[maxn], b[maxn];
int dp[110][100*100 + 10];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i] + b[i];

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += a[i] * a[i] * (n - 2);
		answer += b[i] * b[i] * (n - 2);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int dif = a[i] - b[i];
		for (int j = 0; j <= 100 * i; j++) {
			dp[i][j] = 0;
			if (j >= a[i])
				dp[i][j] |= dp[i - 1][j - a[i]];
			if (j >= b[i])
				dp[i][j] |= dp[i - 1][j - b[i]];
		}
	}
	int ot = 1e9;
	for (int i = 0; i <= 100 * n; i++) {
		if (dp[n][i] == 1) {
			int a = i;
			int b = sum - i;
			ot = min(ot, a * a + b * b + answer);
		}
	}
	cout << ot << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}