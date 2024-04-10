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

ll dp[300100][19];
int n, m, k;
int a[100];
vector  < pii > g[100];
int cnt[300300];
ll get(int mask, int pos){
    if(cnt[mask] == m) return 0;
    ll &res = dp[mask][pos];
    if( res != -1 ) return res;
    res = 0;
    int nmask = mask;
    forit(it, g[pos]){
        int c = it->f;
        if( mask & (1 << c) ){
            
        }
        else {
            res = max(res, get(mask | ( 1 << c), c) + a[c] + it->s);
            nmask |= ( 1 << c);
        }
    }
    for(int i = 0; i < n; i++){
        int c = i;
        if( nmask & (1 << c) ){
            
        }
        else {
            res = max(res, get(mask | ( 1 << c), c) + a[c]);
            nmask |= ( 1 << c);
        }
    }
    return res;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    memset(dp, -1, sizeof dp);
    cin >> n >> m>> k;
    for(int i = 0; i  < n; i++)
        cin >> a[i];
    for(int i = 0; i < k; i++){
        int x, y, c;
        cin >> x >> y >> c;
        g[x-1].pb( mp ( y - 1, c));
    }
    cnt[0] = 0;
    for(int i = 1; i < 300300; i++){
        cnt[i] = cnt[i/2];
        if(i % 2 == 1) cnt[i]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans =max(ans, get(1<<i, i) + a[i]);
    }
    cout << ans << endl;






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}