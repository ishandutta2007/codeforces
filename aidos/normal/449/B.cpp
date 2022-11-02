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

const ll inf = (1ll << 60);

#define MAXN (int) (1e7)
using namespace std;
int n, m, k;
vector < pii > v[100100];
ll dp[100100];
set < pll > S;
ll ans = 0;
int used[100100], b[100100], ff[100100];
int sz[100100];
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int l, r, y;
        scanf("%d%d%d", &l, &r, &y);
        v[l].pb(mp(r, y));
        v[r].pb(mp(l, y));
    }
    for(int i = 1; i<=n;i++){
        ff[i] = -1;
    }
    for(int i = 0; i < k; i++){
        int len, b;
        scanf("%d%d", &b, &len);
        if(sz[b]) {
            ff[b] = min(ff[b], len);
        }
        else ff[b] = len;
        sz[b]++;
    }
    for(int i = 1; i<=n; i++){
        if( i == 1) dp[i] = 0;
        else dp[i] = inf;
        S.insert(mp(dp[i], i));
    }    
    while(S.size() > 0){
        pll a = *S.begin();
        S.erase(S.begin());
        int k = a.s;
        if( k == 1){
            for(int i = 2; i <= n; i++){
                if( ff[i] != -1){
                    S.erase(mp(dp[i], i));
                    dp[i] = ff[i];
                    S.insert(mp(dp[i], i));
                }
            }
        }
        for(int i = 0; i<v[k].size(); i++){
            int to = v[k][i].f;
            ll dif = v[k][i].s;
            if( a.f + dif < dp[to]){
                S.erase(S.find(mp(dp[to], to)));
                ff[to] = -1;
                dp[to] = a.f + dif;
                S.insert(mp(dp[to], to));
            }
            else if( a.f + dif == dp[to] && ff[to] != -1){
                ff[to] = -1;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(ff[i] != -1){
            ans++;
        }
    }
    cout << k-ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}