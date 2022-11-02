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
int a[2010];
int dp[2020][2020][2][2];
int d[2020][2020][2][2];
int n;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		--a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int cur = 0;
			for(int x = 0; x < 2; ++x){
				for(int y = x; y < 2; y++){
					dp[i][j][x][y] = dp[i][j-1][x][y];
				}
			}
			for(int x = 0; x < 2; x++){
				for(int y = x; y <= a[j]; y++){
					dp[i][j][x][a[j]] = max(dp[i][j][x][a[j]], dp[i][j-1][x][y]+1);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j >= 1; j--){
			int cur = 0;
			for(int x = 0; x < 2; ++x){
				for(int y = x; y < 2; y++){
					d[i][j][x][y] = d[i][j+1][x][y];
				}
			}
			for(int x = 0; x < 2; x++){
				for(int y = x; y <= a[j]; y++){
					d[i][j][x][a[j]] = max(d[i][j][x][a[j]], d[i][j+1][x][y]+1);
				}
			}
		}
	}
	int ans = 0;
	for(int x = 0; x < 2; x++){
		for(int y = x; y < 2; y++){
			ans = max(ans, dp[1][n][x][y]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			for(int x1 = 0; x1 < 2; x1++){
				for(int x2 = x1; x2 < 2; x2++){
					for(int x3 = x2; x3 < 2; x3++){
						for(int x4 = x3; x4 < 2; x4++){
							for(int x5 = x4; x5 < 2; x5++){
								for(int x6 = x5; x6 < 2; x6++){
									ans = max(ans, dp[1][i-1][x1][x2] + d[j][i][x3][x4] + d[n][j+1][x5][x6]);
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
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