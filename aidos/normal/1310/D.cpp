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
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
int ans = 1e9;
int dp[88];
int d[88];
int p[88];
int a[88][88];
int u[88];
void calc() {
	for(int i = 0; i < n; i++) {
		dp[i] = 1e9;
	}
	dp[0] = 0;
	for(int j = 0; j < k; j++) {
		for(int i = 0; i < n; i++) {
			d[i] = dp[i];
			dp[i] = 1e9;
		}
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < n; y++) {
				if(u[x] != u[y]) {
					dp[x] = min(dp[x], d[y] + a[y][x]);
				}
			}
		}
	}
	ans = min(ans, dp[0]);
}
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	for(int it = 0; it < 4000; it++) {
		random_shuffle(p, p + n);
		for(int i = 0; i < n/2; i++)
			u[p[i]] = 1;

		for(int i = n/2; i < n; i++)
			u[p[i]] = 2;
		calc();
	}
	cout << ans << "\n";
}

int main () {
	srand(time(0));
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}