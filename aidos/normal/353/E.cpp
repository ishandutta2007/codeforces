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

#define MAXN (int) (1e6+10)
using namespace std;
int n;
vector < int > g[MAXN], gr[MAXN];
char c[MAXN];
bool used[MAXN];
void dfs(int x){
    used[x] = 1;
    for(int i = 0; i < g[x].size(); i++){
        int to = g[x][i];
        dfs(to);
    }
}
void rdfs(int x){
    used[x] = 1;
    for(int i = 0; i < gr[x].size(); i++){
        int to = gr[x][i];
        rdfs(to);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s", &c);
    n = strlen(c);

    for(int i = 0; i < n; i++){
        int r = (i + 1) % n;
        if( c[i] == '0' ){
            g[i].pb( r );
            gr[r].pb(i);
        }
        else {
            g[r].pb(i);
            gr[i].pb(r);
        }
    }
    int ans = 0;
    for(int i = 0;i < n; i++){
        if( !used[i] && gr[i].size() && g[i].size()){
            ans++;
            dfs(i);
            rdfs(i);
        }
    }
    for(int i = 0; i < n; i++) 
        if(!used[i]) {
            ans++;
            dfs(i);
            rdfs(i);
        }
    cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}