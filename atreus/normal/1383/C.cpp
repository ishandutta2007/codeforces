#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;

int adj[22];
int dp[(1 << 20) + 10], pd[(1 << 20) + 10];
int cmp[22];
bool mark[(1 << 20) + 10];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int sz;
		string s, t;
		cin >> sz >> s >> t;
		int n = 20;
		for (int i = 0; i < n; i++)
			cmp[i] = (1 << i);
		for (int i = 0; i < n; i++)
			adj[i] = 0;
		for (int i = 0; i < sz; i++){
			int x = (int)s[i] - 'a';
			int y = (int)t[i] - 'a';
			if (x != y)
				adj[x] |= (1 << y);
			for (int j = 0; j < n; j++){
				if (cmp[j] & (1 << x))
					cmp[j] |= cmp[y];
				if (cmp[j] & (1 << y))
					cmp[j] |= cmp[x];
			}
		}
		dp[0] = 1;
		for (int mask = 1; mask < (1 << n); mask++){
			dp[mask] = 0;
			for (int i = 0; i < n; i++){
				if (mask & (1 << i))
					dp[mask] |= (dp[mask^(1<<i)] and (adj[i] & mask) == 0);
			}
		}
		for (int mask = 1; mask < (1 << n); mask++){
			if (dp[mask]){
				pd[mask] = __builtin_popcount(mask);
				continue;
			}
			pd[mask] = 0;
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					pd[mask] = max(pd[mask], pd[mask^(1<<i)]);
		}
		int answer = 0;
		for (int i = 0; i < n; i++){
			if (!mark[cmp[i]]){
				answer += 2 * __builtin_popcount(cmp[i]) - pd[cmp[i]] - 1;
				mark[cmp[i]] = 1;
			}
		}
		for (int i = 0; i < n; i++)
			mark[cmp[i]] = 0;
		cout << answer << endl;
	}
}