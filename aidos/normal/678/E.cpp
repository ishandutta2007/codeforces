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

double dp[20][1<<19];
int n;
double p[20][20];
bool used[20][1<<19];

double get(int pos, int mask){
	if(mask == (1<<n)-1) return pos == 0;
	if(used[pos][mask]) return dp[pos][mask];
	used[pos][mask] = 1;
	for(int i = 0; i < n; i++){
		if(mask & (1<<i)) continue;
		dp[pos][mask] = max(dp[pos][mask], p[pos][i] * get(pos, mask | (1<<i)) + p[i][pos] * get(i, mask| (1<<i)));
	}
	return dp[pos][mask];
}


void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			scanf("%lf", &p[i][j]);
		}
	double ans = 0.0;
	for(int i = 0; i < n; i++){
		ans = max(ans, get(i, (1<<i)));
	}
	printf("%.12lf\n", ans);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}