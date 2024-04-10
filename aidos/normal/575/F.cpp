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

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int n;

ll dp[25050];
ll dp2[25050];
int l[5050], r[5050];

ll get(int pos, int x){
    if(pos < l[x]) return l[x] - pos;
    if( pos > r[x]) return pos - r[x];
    return 0;
}
int a[20100];
int sz = 0;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    for(int i = 0; i < 20002; i++){
        dp[i] = (1ll<<50);
    }
    cin >> n >> l[0];
    r[0] = l[0];
    a[sz++] = l[0];
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        a[sz++] = l[i];
        a[sz++] = r[i];
    }
    sort(a, a + sz);
    sz = unique(a, a +sz) - a;
    for(int i = 0; i < sz; i++)
        if( l[0] == a[i]){
            dp[i] = 0;
        }
    for(int i = 1; i <= n; i++){
        ll mini = ( 1ll << 54);
        for(int j = 0; j < sz; j++){
            mini = min(dp[j] - a[j], mini);
            dp2[j] = mini + a[j];
        }
        mini = ( 1ll << 54);
        for(int j = sz-1; j >= 0; j--){
            mini = min(dp[j] + a[j], mini);
            dp2[j] = min(mini - a[j], dp2[j]);
        }
        for(int j = 0; j < sz; j++){
            dp[j] = dp2[j] + get(a[j], i);
        }

    }   
    ll ans = ( 1ll << 50);
    for(int i = 0; i < sz; i++)
        ans = min(ans, dp[i]);
    cout << ans << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}