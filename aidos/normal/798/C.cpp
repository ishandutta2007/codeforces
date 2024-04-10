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
int n;
int a[200200];
int dp[200200][3];
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int g = a[0];
	for(int i = 0; i < n; i++){
		g = __gcd(a[i], g);
	}

	cout << "YES\n";
	if(g > 1){
		cout << 0 << endl;
		return;
	}
	dp[0][0] = dp[0][1] = inf;
	dp[0][a[0] & 1] = 0;
	for(int i = 1; i < n; i++){
		int x = a[i] & 1;
		if(x == 1){
			dp[i][0] = min(dp[i-1][0] + 2, dp[i-1][1] + 1);
			dp[i][1] = dp[i-1][0];
		}
		else {
			dp[i][0] = min(dp[i-1][1] + 2, dp[i - 1][0]);
			dp[i][1] = inf;
		}
	}
	int ans = dp[n-1][0];
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