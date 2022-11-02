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
const int maxn = (int) 5e3 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m, k;
int a[maxn];
int dp[maxn][maxn];
int rec(int l, int r) {
	int cnt = n - (r-l+1) + 1;
	if(cnt == m) {
		return max(a[l], a[r]);
	}
	int &res = dp[l][r];
	if(res != -1) {
		return res;
	}
	if(cnt <= k) {
		res = max(rec(l, r-1), rec(l+1, r));
		return res;
	}
	res = min(rec(l, r-1), rec(l+1, r));
	return res;
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	if(k >= m) {
		int ans = 0;
		for(int i = 1; i <= m; i++) {
			ans = max(ans, a[i]);
			ans = max(ans, a[n - i + 1]);
		}
		cout << ans << "\n";
		return;
	}
	cout << rec(1, n) << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}