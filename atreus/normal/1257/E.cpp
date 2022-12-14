#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn], dp[maxn], pd[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;
	for (int i = 1; i <= k1; i++){
		int x;
		cin >> x;
		a[x] = 1;
	}
	for (int i = 1; i <= k2; i++){
		int x;
		cin >> x;
		a[x] = 2;
	}
	for (int i = 1; i <= k3; i++){
		int x;
		cin >> x;
		a[x] = 3;
	}
	for (int i = 1; i <= n; i++)
		dp[i] = dp[i - 1] + (a[i] != 1);
	for (int i = 1; i <= n; i++)
		dp[i] = min(dp[i], dp[i - 1] + (a[i] != 2));
	for (int i = n; i >= 1; i--)
		pd[i] = pd[i + 1] + (a[i] != 3);
	int answer = n;
	for (int i = 0; i <= n; i++)
		answer = min(answer, dp[i] + pd[i + 1]);
	cout << answer << '\n';
}