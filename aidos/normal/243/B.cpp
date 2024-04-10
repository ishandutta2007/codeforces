#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

int n, m, h, t;
vector < int > g[1001000];
vector < pair<int, int> > li;
vector < int>  v1, v2, v3;
bool used[1001000];
bool used2[1001000];
bool ok(int a, int b){
    for(int x: g[a]){
        used2[x] = 1;
    }

    for(int x: g[b]){
        if( x==a) continue;
        if(!used2[x]) {
            v2.pb( x );
            if(v2.size() == t) break;
        }
    }
    if(v2.size() < t){
        for(int x: g[b]){
            if(used2[x]) {
                v2.pb( x );
                used[x] = 1;
                if(v2.size() == t) break;
            }
        }
    }
    for(int x: g[a]){
        if(x == b) continue;
        if(!used[x]) {
            v1.pb( x );
            if(v1.size() == h) break;
        }
    }


    printf("YES\n");
    printf("%d %d\n", a, b);
    for(int x: v1) printf("%d ", x);
    printf("\n");
    for(int x: v2) printf("%d ", x);
    printf("\n");
    exit(0);
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d %d", &n, &m, &h, &t);
    for(int i = 0, a, b; i < m; i++){
        scanf("%d %d", &a, &b);
        g[a].pb( b );
        g[b].pb( a );
        li.push_back(mp(a, b));
    }
    for(int i = 0; i < m; i++){
        int a = li[i].f;
        int b = li[i].s;
        if(g[a].size() >= h + t + 1&& g[b].size() >=t+1){
            ok(a, b);
        }
        if(g[a].size() >= t + 1&& g[b].size() >=h + t+1){
            ok(b, a);
        }
        if(g[a].size() >= h  + 1&& g[b].size() >=h + t+1){
            ok(a, b);
        }
        if(g[a].size() >= h + t + 1&& g[b].size() >=h+1){
            ok(b, a);
        }
    }

    for(int i = 0; i<=n; i++)
        sort(all(g[i]));
    for(int i = 0; i < m; i++){
        int a = li[i].f;
        int b = li[i].s;
//      if(g[a].size() >= h && g[b].size() >= t){
        if(min(g[a].size() - 1, g[b].size() - 1) < min(h, t) || max(g[a].size() - 1, g[b].size() - 1) < max(h, t)) continue;
            if(g[a].size() < g[b].size()) swap(a, b);
                int cnt = 0;
                int a1 = sz(g[a]) - 1;
                int a2 = sz(g[b]) - 1;
                for(int x: g[b]){
                    if(upper_bound(all(g[a]) , x) - lower_bound(all(g[a]) , x)) cnt++;
                }
                if(max(h -a1 + cnt, 0)+max(t -a2 + cnt, 0) <= cnt) ok(a,b);
                if(max(t -a1 + cnt, 0)+max(h -a2 + cnt, 0) <= cnt) ok(b, a);
    }
    cout << "NO\n";
    


    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}