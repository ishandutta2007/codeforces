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
#define sz(a) (int)a.size()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int)1e9 + 7;


using namespace std;

vector<int> g[100100];
ll h[100100];
ll a[100100];
ll u1[100100];
ll u2[100100];
ll ans=0;
int n;
void dfs(int v, int pa){
    h[v] = 0;
    a[v] = 0;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(to != pa){
            dfs(to, v);
            h[v] = max(h[v], max(h[to], a[v] + a[to] + 1));
            a[v] = max(a[to] + 1, a[v]);
        }
    }
}
void DFS(int v, int pa){
    u2[v] = max(u2[v], u1[v]);
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(to != pa){
            u1[to] = u1[v] + 1;
            u2[to] = u2[v];
        }
    }
    ll s1 = 0;
    ll s2 = u2[v];
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(to != pa){
             
            u2[to] = max(u2[to], max(s2, s1+u1[to]));
            u1[to] = max(u1[to], s1);
            
            
            s2 = max(s2, max(h[to], a[to] + 1+s1));
            s1 = max(s1, a[to]+1);
        }
    }
    
    s1 = 0;
    s2 = 0;
    
    for(int i = ((int) g[v].size()); i >0; ){
        i--;
        int to = g[v][i];
        if(to != pa){
             
            u2[to] = max(u2[to], max(s2, s1+u1[to]));
            u1[to] = max(u1[to], s1);
            
            s2 = max(s2, max(h[to], a[to] + 1+s1));
            s1 = max(s1, a[to]+1);
        }
    }
    ans = max(ans, u2[v]    * 1ll * h[v]);

    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(to != pa){
            DFS(to, v);
        }
    }
}


void solve(){
    int cnt = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        g[i].clear();
    }
    ans =0;
    for(int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 0);
    u1[1] = -1;
    u2[1] = 0;
    DFS(1, 0);
    cout << ans<< endl;

}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int t=1;
    //scanf("%d", &t);


    while (t--) solve();


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}