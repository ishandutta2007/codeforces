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
int dp[111][11100];
int a[111];
int b[111];
int n;
int m = 0;
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		m += a[i];
	}
	
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);	
	for(int j = 0; j <= n; j++)
		for(int i = 0; i <= m; i++)
			dp[j][i] = -inf;
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j >= 0; j--){
			for(int x = 0; x <= m; x++){
				if(dp[j][x] >= 0){
					dp[j+1][x + a[i]] = max(dp[j+1][x + a[i]], dp[j][x] + b[i]);
				}
			}
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = m; j >= 0; j--){
			if(dp[i][j] < 0) continue;
			if(dp[i][j] >= m){
				cout << i << " "<< m - j << endl;
				return;
			}
		}
	}
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