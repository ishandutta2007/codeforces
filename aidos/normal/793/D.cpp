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
int dp[90][90][90][4];
int cost[90][90];
int n,k, m;
int get(int l, int r, int k, int d){
	if(k == 0) return 0;
	if(l > r) return inf;
	int &res = dp[l][r][k][d];
	if(res != -1) return res;
	res = inf;
	int x = l - 1;
	if(d) x = r + 1;
	for(int i = l; i <= r; i++){
		if(cost[x][i] <= 1000){
			res = min(res, min(get(l, i - 1, k - 1, 1), get(i + 1, r, k - 1, 0)) + cost[x][i]);
		}
	}
	return res;
}
void solve(){
	memset(dp, -1, sizeof dp);
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cost[i][j] = inf;
		}
	}
	for(int i = 1, a, b, c; i <= m; i++){
		scanf("%d%d%d", &a, &b, &c);
		cost[a][b] = min(cost[a][b], c);
	}
	int ans = inf;
	for(int i = 1; i <= n; i++){
		ans = min(ans, min(get(1, i-1, k-1, 1), get(i + 1, n, k - 1, 0)));
	}
	if(ans == inf) ans = -1;
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