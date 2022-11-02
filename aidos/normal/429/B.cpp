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
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
ll sum[5][1010][1010];
int a[1010][1010];
int n, m;
ll get(int i, int j){
	if(i == 1 ||  i == n || j == m || j == 1){
		return (ll)(-1e18);
	}
	return max(sum[0][i][j-1] + sum[1][i][j+1] + sum[2][i+1][j] + sum[3][i-1][j], sum[0][i-1][j] + sum[1][i+1][j] + sum[2][i][j-1] + sum[3][i][j+1]);
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++){
    	for(int j = 1; j<=m; j++){
    		scanf("%d", &a[i][j]);
    	}
    }
    for(int i=1; i <=n; i++){
    	for(int j = 1; j<=m; j++){
    		sum[0][i][j] = max(sum[0][i-1][j], sum[0][i][j-1]) + a[i][j];
    	}
    }
    for(int i=n; i > 0; i--){
    	for(int j = m; j>0; j--){
    		sum[1][i][j] = max(sum[1][i+1][j], sum[1][i][j+1]) + a[i][j];
    	}
    }
    for(int i=n; i  > 0; i--){
    	for(int j = 1; j<=m; j++){
    		sum[2][i][j] = max(sum[2][i+1][j], sum[2][i][j-1]) + a[i][j];
    	}
    }
    
    for(int i=1; i <=n; i++){
    	for(int j = m; j>0; j--){
    		sum[3][i][j] = max(sum[3][i-1][j], sum[3][i][j+1]) + a[i][j];
    	}
    }
    ll ans = (ll)(-1e18);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		ll in = (ll)(-1e18);
    		in = get(i, j);//max(sum[0][i][j-1] + sum[1][i][j+1] + sum[2][i+1][j] + sum[3][i-1][j], sum[0][i-1][j] + sum[1][i+1][j] + sum[2][i][j-1] + sum[3][i][j+1]);
    		ans = max(in, ans);
    	}
    }
    cout << ans << endl;
	#ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}