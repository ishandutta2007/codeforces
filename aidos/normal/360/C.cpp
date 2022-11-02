#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
int dp[2020][2020];
int cd[2020][2020];
string s;
int g[2020];
void add(int &v, int u) {
	v += u;
	if(v>=mod) v -= mod;
}
void solve(){
	cin >> n >> k >> s;
	g[0] = 1;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int t = 0; t <= k; t++){
			dp[i][t] = g[t] * 1ll * (s[i-1] - 'a') % mod;
		}
		for(int t = 0; t <= k; t++){
			for(int pref = 0; i - pref-1 >= 0 && (1+pref)*(n - i + 1) <= t; pref++) {
				add(dp[i][t], dp[i-pref-1][t-(1+pref) * (n-i+1)] *1ll * ('z' - s[i-1]) % mod);
			}
		}
		
		for(int t = 0; t <= k; t++){
			add(g[t], dp[i][t]);
		}
	}
	int ans = 0;
	for(int i = 0;i <= n; i++) add(ans, dp[i][k]);
	cout << ans << "\n";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}