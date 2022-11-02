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
const int maxn = (int) 2e5 + 10;

using namespace std;
int mod=1000000007;

int n, m;
int cc[maxn];
int sz = 2;
vector < int > g[maxn];
vector < int > gg[maxn];
void dfs(int x, int cur){
    cc[x] = cur;
    for(int i = 0; i < g[x].size(); i++){
        int to = g[x][i];
        if(cc[to] == (cur ^ 1)){
            cout << "0" << endl;
            exit(0);
        }
        if(!cc[to]) dfs(to, cur);
    }
    for(int i = 0; i < gg[x].size(); i++){
        int to = gg[x][i];
        if(cc[to] == cur){
            cout << "0" << endl;
            exit(0);
        }
        if(!cc[to]) dfs(to, (cur^1));
    }
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b, c; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(c){
            g[a].pb(b);
            g[b].pb(a);
        }
        else {
            gg[a].pb(b);
            gg[b].pb(a);
        }
    }
    int cnt = 0;
    for(int i = 1;i <=n; i++){
        if(!cc[i]){
            cnt++;
            dfs(i, sz);
            sz+=2;
        }
    }
    int ans = 1;
    for(int i = 1; i < cnt; i++){
        ans = (ans * 2ll) % mod;
    }
    cout << ans << endl;



                                          
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}