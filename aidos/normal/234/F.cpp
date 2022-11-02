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
int n;
int a, b;
int dp[202][40100];
int d[202][40100];
int h[202];
int ss = 0;
void solve(){
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
		ss += h[i];
	}
	for(int i = 0; i <= n;i++)for(int j = 0; j <= a; j++) dp[i][j] = d[i][j] = ss + 1;
	dp[0][0] = 0;
	d[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j=0; j <= a; j++) {
			d[i][j] = min(d[i-1][j], dp[i-1][j] + min(h[i], h[i-1]));
			if(j >= h[i]) {
				dp[i][j] = min(dp[i-1][j-h[i]], d[i-1][j-h[i]] + min(h[i], h[i-1]));
			}
		}
	}
	int ans = ss + 1;
	for(int i = 0; i <= a; i++) {
		if(i + b >= ss) {
			ans = min(ans, min(dp[n][i], d[n][i]));
		}
	}
	if(ans > ss) ans = -1;
	cout << ans << "\n";
}
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}