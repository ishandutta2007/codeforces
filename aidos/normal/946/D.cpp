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

using namespace std;
int n, m, k;
char c[555];
int dp[555];
int d[555];
int sum[555];
int g[555];
void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= k; j++){
			d[j]  = dp[j];
			dp[j] = inf;
		}
		scanf("%s", c);
		for(int j = 0; j < m; j++){
			sum[j+1] = sum[j] + (c[j] == '1');
			g[j+1] = inf;
		}
		for(int j = 0; j < m; j++){
			if(c[j] == '1'){
				for(int t = j; t < m; t++){
					if(c[t]=='1'){
						int dd = sum[t+1] - sum[j];
						g[dd] = min(g[dd], t - j + 1);
					}
				}
			}
		}
		int all = sum[m];
		for(int j = 0; j <= k; j++){
			for(int t = 0; t <= all && t <= j; t++){
				dp[j] = min(dp[j], d[j-t] + g[all - t]);
			}
		}
	}
	printf("%d\n", dp[k]);
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}