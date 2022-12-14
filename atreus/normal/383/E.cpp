#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

int dp[(1 << 24) + 1];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		for (int mask = 1; mask < 8; mask++){
			int alph = 0;
			for (int j = 0; j < 3; j++)
				if (mask & (1 << j))
					alph |= (1 << (int)(s[j] - 'a'));
			int k = __builtin_popcount(mask);
			int sign = 1;
			if (k == 2)
				sign = -1;
			dp[alph] += sign;
		}
	}
	for (int i = 23; i >= 0; i--)
		for (int mask = 0; mask < (1 << 24); mask++)
			if (mask & (1 << i))
				dp[mask] += dp[mask ^ (1 << i)];
	int answer = 0;
	for (int mask = 0; mask < (1 << 24); mask++)
		answer ^= (dp[mask] * dp[mask]);
	cout << answer << endl;
}