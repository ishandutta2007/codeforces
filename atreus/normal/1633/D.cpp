#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int dp[1000 + 10], pd[12 * 1000 + 10];
int b[maxn], c[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int p = 1000;
	for (int i = 1; i <= p; i++)
		dp[i] = i - 1;
	dp[1] = 0;
	for (int i = 1; i <= p; i++)
		for (int x = 1; x <= i; x++)
			if (i + i / x <= p)
				dp[i + i / x] = min(dp[i + i / x], dp[i] + 1);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		k = min(k, 12 * n);
		memset(pd, 0, sizeof pd);
		for (int i = 1; i <= n; i++)
			for (int x = k; x >= dp[b[i]]; x--)
				pd[x] = max(pd[x], pd[x - dp[b[i]]] + c[i]);
		cout << *max_element(pd, pd + k + 1) << '\n';
	}
}