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
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 28);

#define MAXN (int) (1e7)
using namespace std;
int n;
vector < int > v, ans;
int d[65];
int dp[111][(1ll<< 17)];
int a[111];
bool is_p(int k){
    for(int i = 2; i<k; i++) if( k  % i == 0) return 0;
    return 1;
}
int get(int k, int mask){
    if( k == n) return 0;
    int &res= dp[k][mask];
    if( res != -1) return res;
    res = inf;
    for(int i = 1; i< 59; i++){
        if( (mask & d[i]) == 0){
            res = min( res, get(k+1, mask | d[i]) + abs(a[k] - i));
        }
    }
    return res;
}
void go(int k, int mask, int sum){
    if( k==n) return;
    for(int i = 1; i < 59; i++){
        if( (mask & d[i]) == 0 && get(k+1, mask | d[i]) + abs(a[k] - i) == sum){
            ans.pb(i);
            go(k+1, mask | d[i], sum - abs(a[k] - i));
            return;
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 2; i<=58; i++){
        if( is_p(i)) v.pb( i ) ;
    }
    for(int i = 0; i<v.size(); i++){
        for(int j = v[i]; j < 59; j+= v[i]){
            d[j] |= (1<<i);
        }
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    go( 0, 0, get(0, 0));
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}