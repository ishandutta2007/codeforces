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
int dp[555][555];
int d[555][555];
int x, n, m, b, mod;
int c;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> x >> n >> m >> mod;
    if(mod == 1){
    	cout << 0 << endl;
    	return 0;
    }

    for(int i = 0; i < x; i++){
    	cin >> c;
    	for(int j = 0; j <= n; j++){
    		for(int k = 0; k <= m; k++){
    			d[j][k] = dp[j][k];
    			dp[j][k] = 0;
    		}
    	}
    	dp[0][0] = 1;
    	for(int j = 1; j <= n; j++){
    		for(int k = 0; k <= m; k++){
    			if(k >= c) dp[j][k] = dp[j-1][k-c] + d[j][k];
    			else dp[j][k] = d[j][k];
    			if(dp[j][k] >= mod) dp[j][k] -= mod;
    		}
    	}
    }
    int sum = 0;
    for(int i = 0; i <=m; i++){
    	sum += dp[n][i];
    	sum %= mod;
    }
    cout << sum << endl;

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}