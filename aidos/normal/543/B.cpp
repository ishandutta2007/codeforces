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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int n, m;
vector < int > g[3030];
int dp[3030][3030];
int mx = 1000100;
bool used[3030];
void calc(int x){
	queue < int > q;
	q.push(x);
	for(int i = 1; i <= n; i++){
		dp[x][i]=mx;
		used[i] = 0;
	}
	used[x] = 1;
	dp[x][x] = 0;
	while(q.size() > 0){
		int cur  = q.front();
		q.pop();
		for(int j = 0; j < g[cur].size(); j++){
			int to  = g[cur][j];
			if(used[to]) continue;
			dp[x][to] = dp[x][cur] + 1;
			used[to] = 1;
			q.push(to);
		}
	}
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
    	int x, y;
    	scanf("%d %d", &x, &y);
    	g[x].pb(y);
    	g[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
    	calc(i);
    }
    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    int ans = mx;
    if(dp[s1][t1] <= l1 && dp[s2][t2] <= l2){
    	ans = dp[s1][t1] + dp[s2][t2];
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(dp[i][j] + dp[s1][i] + dp[j][t1] > l1) continue;
    		if(dp[i][j] + dp[s2][i] + dp[j][t2]  <= l2) ans = min(ans, dp[i][j] + dp[s2][i] + dp[j][t2]+dp[s1][i] + dp[j][t1]);
    		if(dp[i][j] + dp[t2][i] + dp[j][s2]  <= l2) ans = min(ans, dp[i][j] + dp[t2][i] + dp[j][s2]+dp[s1][i] + dp[j][t1]);
    	}
    }
    if(ans == mx) cout << -1 << endl;
    else cout << m - ans << endl;





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}