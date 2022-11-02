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
int n, m;
int dp[41][1<<16];
int a[44];
int b[44];
int c[44];
void solve(){
	cin >> n >> m;
	if(n<m) swap(n, m);
	int t = 1;
	for(int i = 0; i < m; i++) t *= 3;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j < t; j++) dp[i][j] = inf;
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < t; j++){
			int tt = j;
			for(int k = 0; k < m; k++){
				a[k] = tt % 3;
				tt /= 3;
			}
			for(int mask = 0; mask < (1<<m); mask++) {
				for(int x = 0; x < m; x++) b[x] = a[x], c[x] = 1;
				for(int x = 0; x < m; x++) {
					if(mask & (1<<x)) {
						c[x] = 2;
					}
				}
				int cnt = 0;
				int nmask = 0;
				for(int x = 0; x < m; x++) {
					if(c[x] == 1) {
						if(x + 1 < m && c[x+1] == 2) c[x] = 0;
						else if(x > 0 && c[x-1] == 2) c[x] = 0;
						else if(b[x] == 2) c[x] = 0;
					}
					if(b[x] == 1 && c[x] != 2) cnt++;
				}
				if(cnt>0) continue;
				for(int x = m-1; x >= 0; x--) nmask = nmask * 3 + c[x];
				dp[i][nmask] = min(dp[i-1][j] + __builtin_popcount(mask), dp[i][nmask]);
			}
		}
	}
	int ans = inf;
	for(int j = 0; j < t; j++) {
		int tt = j;
		
		while(tt > 0 && tt % 3 != 1) {
			tt/=3;
		}
		if(tt == 0) ans = min(ans, dp[n][j]);
	}
	cout << n*m - ans << "\n";
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