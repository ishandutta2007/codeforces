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

const int inf = (1 << 29) - 1;
const int maxn = (int)3e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int x;
ll a[maxn];
ll dp[maxn][3];
void solve() {
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + a[i];
		dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + a[i] * x;
		dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + a[i];
		for(int j = 0; j < 3; j++) {
			dp[i][j] = max(dp[i][j], 0ll);
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans << "\n";
}
int main () {
	int t = 1;
    //scanf("%d", &t);
    for(int i=1; i<=t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}

//