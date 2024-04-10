#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int dp[80][1100 * 1000 + 10];
string s;
int cnt[1100 * 1000];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	s = " " + s;
	dp[0][0] = 1;
	int answer = 0;
	int l = 20;
	for (int mask = 1; mask < (1<<l); mask++){
		for (int i = 0; i < l; i++){
			if (mask & (1 << i)){
				int x = i + 1;
				while (x){
					cnt[mask] ++;
					x /= 2;
				}
				cnt[mask] += cnt[mask ^ (1 << i)];
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		dp[i][0] = 1;
		for (int mask = 1; mask < (1<<l); mask++){
			int me = 0;
			for (int j = i - 1; j >= 0; j--){
				if (cnt[mask] - 6 > j)
					break;
				if (s[j + 1] == '1'){
					if (i - j - 1 > 10)
						 break;
					me += (1 << (i - j - 1));
				}
				if (me > l)
					break;
				int tme = me - 1;
				if (tme == -1 or (mask & (1<<tme)) == 0)
					continue;
				dp[i][mask] += dp[j][mask];
				if (dp[i][mask] >= mod)
					dp[i][mask] -= mod;
				dp[i][mask] += dp[j][mask^(1<<tme)];
				if (dp[i][mask] >= mod)
					dp[i][mask] -= mod;
			}
			if (__builtin_popcount(mask+1) == 1){
				answer += dp[i][mask];
				if (answer >= mod)
					answer -= mod;
			}
		}
	}
	cout << answer << endl;
}