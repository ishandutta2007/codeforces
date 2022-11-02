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
int const maxn = 200100;
using namespace std;

vector  < int > g[maxn], gr[maxn];
int ans[maxn];
int used[maxn];
int n;
int dfs(int x){
    used[x] = 1;
    int cnt = 0;
    for(int i = 0; i< g[x].size(); i++){
        int to = g[x][i];
        if(!used[to]) {
            cnt += dfs(to);
        }
    }
    for(int i = 0; i< gr[x].size(); i++){
        int to = gr[x][i];
        if(!used[to]) {
            cnt += dfs(to) + 1;
        }
    }
    return cnt;
}
void dfs2(int x, int a){
    used[x] = 2;
    ans[x] = a;
    for(int i = 0; i< g[x].size(); i++){
        int to = g[x][i];
        if(used[to]!=2) {
            dfs2(to, a+1);
        }
    }
    for(int i = 0; i< gr[x].size(); i++){
        int to = gr[x][i];
        if(used[to]!=2) {
            dfs2(to, a-1);
        }
    }
    
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
        
    cin >> n;
    for(int i = 1, x, y; i < n; i++){
        cin >> x >> y;
        g[x].pb(y);
        gr[y].pb(x);
    }
    ans[1]=dfs(1);
    used[1] = 2;
    for(int i = 0; i < g[1].size(); i++){
        dfs2(g[1][i], ans[1]+1);
    }
    for(int i = 0; i < gr[1].size(); i++){
        dfs2(gr[1][i], ans[1]-1);
    }
    int mini = inf;
    for(int i = 1; i<= n; i++) mini = min(ans[i], mini);

    cout << mini << endl;
    for(int i = 1; i <= n; i++){
        if( ans[i] == mini) cout << i << " ";

    }



    #ifdef LOCAL
        cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}