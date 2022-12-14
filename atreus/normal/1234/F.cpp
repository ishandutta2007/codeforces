#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int dp[(1 << 20) + 5];
bool mark[22];

int main(){
	ios_base::sync_with_stdio (false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		memset(mark, 0, sizeof mark);
		int mask = 0;
		for (int j = i; j < n; j++){
			int me = (int)(s[j] - 'a');
			if (mark[me] == true)
				break;
			mark[me] = true;
			mask |= (1 << me);
			dp[mask] = j - i + 1; // number of ones in mask
		}
	}
	for (int mask = 0; mask < (1 << 20); mask++)
		for (int i = 0; i < 20; i++)
			if (mask & (1 << i))
				dp[mask] = max(dp[mask], dp[mask^(1<<i)]);
	int tot = (1 << 20) - 1;
	int answer = 0;
	for (int mask = 0; mask < (1 << 20); mask++)
		answer = max(answer, dp[mask] + dp[tot^mask]);
	cout << answer << endl;
}