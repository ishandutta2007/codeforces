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

int n, m;
int b[100100];
int d[100100];
vector < pii > g[100100], gg[100100];
vector < int > vv[100100];
bool used[100100];
vector < int > cur[100100];
int dis[100100];
pii pa[100100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);

    for(int i = 0, x, y, c; i < m; i++){
        scanf("%d %d %d", &x, &y, &c);
        g[x].pb( mp(y, c));
        g[y].pb( mp(x, c));
    }
    for(int i = 0; i < n; i++){
        b[i] = n * 1000;
        d[i] = n * 1000;
    }
    queue < int > q;
    q.push( 0 );
    used[0] = 1;
    b[0] = 0;
    while( q.size() > 0 ){
        int x = q.front();
        q.pop();
        forit(it, g[x]){
            int to = it->f;
            if(used[to]) continue;
            q.push(to);
            used[to] = 1;
            b[to] = b[x] + 1;
        }
    }
    memset(used, 0, sizeof used);
    q.push( n - 1);
    used[n-1] = 1;
    vv[0].pb( n - 1 ); 
    d[n - 1] = 0;
    while( q.size() > 0 ){
        int x = q.front();
        q.pop();
        forit(it, g[x]){
            int to = it->f;
            if(used[to] || it->s != 0) continue;
            q.push(to);
            used[to] = 1;
            d[to] = d[x] + 1;
            vv[ d[to] ].pb( to );
        }
    }
    int mini = -1;
    for(int i = 0; i < n; i++){
        forit(it, vv[i]){
            if( mini == -1 || b[mini] > b[*it] )
                mini = *it;
        }
    }
    for(int i = 0; i < n; i++){
        forit(it, vv[i]){
            if( b[mini] == b[*it] )
                cur[b[mini]].pb( *it );
        }
    }

    for(int i = b[mini] - 1; i >= 0; i--){
        int mi = 11;
        forit(it, cur[i+1]){
            int v = *it;
            forit(it2, g[v]){
                int to = it2->f;
                int w = it2->s;
                if( b[to] + 1 == b[v])
                    mi = min(w, mi);
            }
        }
        forit(it, cur[i+1]){
            int v = *it;
            forit(it2, g[v]){
                int to = it2->f;
                int w = it2->s;
                if( w != mi || b[to] + 1 != b[v]) continue;
                gg[to].pb( mp ( v, w));
                cur[i].pb( to );
            }
        }
        sort(all(cur[i]));
        cur[i].resize(unique(all(cur[i])) - cur[i].begin());
    }
    vector < int > ans;
    q.push( 0 );
    while( q.size() > 0){
        int x = q.front();

        q.pop();
        if( b[x] == b[mini] ) ans.pb( x );
        forit( it, gg[x] ){
            int to = it->f;
            int w = it->s;
            pa[to] = mp(x, w);
            q.push( to );
        }
    }
    int mi = -1;

    forit(it, ans){
        int to = *it;
        if( mi == -1 || d[mi] > d[to]) mi = to;
    }
    int y = mi;
    ans.clear();
    while( y != 0){
        ans.pb( pa[y].s );
        y = pa[y].f;
    }
    if (ans.empty()) ans.pb(0);
    for(int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
    }
    printf("\n");
    y = mi;
    ans.clear();
    while( y != 0){
        ans.pb( y );
        y = pa[y].f;

    }   
    ans.pb( 0 );
    reverse(all(ans));
    ans.pop_back();
    while( mi != n-1){
        int x = -1;
        forit(it, g[mi]){
            if( d[it->f] + 1== d[mi] && it->s == 0){
                x = it->f;
            }
        }
        ans.pb( mi );
        mi = x;
    }
    ans.pb( n - 1 );
    cout << ans.size() << endl;
    forit(it, ans) printf("%d ", *it);
    printf("\n");

    







    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}