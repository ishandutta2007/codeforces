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

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
ll a[111000];
ll b[111000];
int n, m; 
int t[111000];
int x[111000];
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    ll sum1 = 0;
    ll sum2 = 0;
    ll sum3 = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &t[i]);
        sum1 += t[i];
    }
    sum3 = sum1;
    sort(t, t + n);
    reverse(t, t+n);
    //cout << t[0] << endl;
    for(int i = 0; i < m; i++){
        scanf("%d", &x[i]);
        sum2 += x[i];
    }
    sort(x, x + m);
    reverse(x, x+m);

    ll ans = (1ll << 62);
    for(int i = 0; i < n; i++){
        sum1 -= t[i];
        double l = log(sum2);
        double k = log((i+1));
        double z = log(max(sum1, 1ll));
        if( max(l + k,z ) > log(ans)) continue;
        ans = min( ans, sum2 * 1ll * ( i + 1 ) + sum1);
    }
    sum1 = sum3;
    //cout << ans << endl;
    for(int i = 0; i < m; i++){
        sum2 -= x[i];
        double l = log(sum1);
        double k = log((i+1));
        double z = log(max(sum2, 1ll));
        if( max(l + k,z) > log(ans)) continue;
        ans = min( ans, sum1 * 1ll * ( i + 1 ) + sum2);
    }
    cout << ans << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}