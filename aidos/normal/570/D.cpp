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
const int maxn = (int) 1e5 + 10;

using namespace std;


char c[500500];
vector < int > g[500500];
vector < int > x[500500];
vector < int > t[500500];
int tin[500500];
int tout[500500];
int len[500500];
int n, m;
int tim = 0;

void dfs(int v, int dis = 0){
    len[v] = dis;
    tin[v] = tim++;
    x[dis].pb( 1 << ( c[v] - 'a'));
    t[dis].pb(v);
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        dfs(to, dis + 1);
    }
    tout[v] = tim++;
}

int getl(int a, int h){
    if( t[h].size() == 0) return inf;
    int l = 0;
    int r = t[h].size() - 1;
    int ans = inf;
    while(l<=r){
        int mid = ( l + r )  >> 1;
        if(tin[t[h][mid]] >= tin[a] && tout[a] >= tout[t[h][mid]]){
            r = mid - 1;
            ans = mid;
        }
        
        else if( tin[t[h][mid]] >= tin[a]) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
int getr(int a, int h){
    if( t[h].size() == 0) return -1;
    int l = 0;
    int r = t[h].size() - 1;
    int ans = -1;
    while(l<=r){
        int mid = ( l + r )  >> 1;
        if(tin[t[h][mid]] >= tin[a] && tout[a] >= tout[t[h][mid]]){
            l = mid + 1;
            ans = mid;
        }
        else if( tin[t[h][mid]] >= tin[a]) {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d\n", &n, &m);
    for(int i = 1; i < n; i++){
        int x;
        scanf("%d ", &x);
        g[x-1].pb(i);
    }
    scanf("%s\n", &c);
    
    dfs(0);
    for(int i = 0; i < 500010; i++){
        for(int j = 1; j < x[i].size(); j++)
            x[i][j] ^= x[i][j-1];
    }
    for(int i = 0, a, h; i < m; i++){
        scanf("%d %d\n", &a, &h);
        a--;
        h--;
        int l = getl(a, h);
        int r = getr(a, h);

        if( l > r) {
            if( n==5000001)
                printf("Yes1\n");
            else printf("Yes\n");
        }
        else {
            int ans = x[h][r];
            if( l > 0 ) ans ^= x[h][l-1];
            if(__builtin_popcount(ans) <= 1) {
                if( n==5000001)
                    printf("Yes1\n");
                else printf("Yes\n");
            }
            else {
                
            if( n==5000001)
                printf("No1\n");
            else printf("No\n");
            }
        }
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}