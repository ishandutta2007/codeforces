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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int dp[555][555];
int x[555];
ll ans[555];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j=1; j <= n; j++) cin >> dp[i][j];
	}
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int k = n; k >= 1; k--) {
		
		for(int j = k; j <= n; j++) {
			for(int i = k; i <= n; i++) {
				dp[x[i]][x[k]] = min(dp[x[i]][x[k]], dp[x[i]][x[j]] + dp[x[j]][x[k]]);
			}
		}
		for(int j = k; j <= n; j++) {
			for(int i = k; i <= n; i++) {
				dp[x[k]][x[i]] = min(dp[x[k]][x[i]], dp[x[k]][x[j]] + dp[x[j]][x[i]]);
			}
		}
		for(int i = k; i <= n; i++) {
			for(int j = k; j <= n; j++) {
				dp[x[i]][x[j]] = min(dp[x[i]][x[j]], dp[x[i]][x[k]] + dp[x[k]][x[j]]);
			}
		}
		for(int i = k; i <= n; i++) {
			for(int j = k; j <= n; j++) {
				ans[k] += dp[x[i]][x[j]];
			}
		}
	}
	for(int i = 1; i <= n;i ++) cout << ans[i] << "\n";
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