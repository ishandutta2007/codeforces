#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxV = (int) 1e6 + 1;
const int mod = (int) 1e9 + 7;

vector<int> divs[MaxV + 9];
ll dp[MaxV + 9] = { 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 1; i <= MaxV; ++i)
		for (int j = i; j <= MaxV; j += i)
			divs[j].push_back(i);

	for (int i = 1; i <= MaxV; ++i)
		reverse(divs[i].begin(), divs[i].end());

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		for (const int &d : divs[x])
			(dp[d] += dp[d - 1]) %= mod;
	}

	const ll ans = accumulate(dp, dp + MaxV + 1, -1LL);
	cout << ((ans % mod) + mod) % mod;
	return 0;
}