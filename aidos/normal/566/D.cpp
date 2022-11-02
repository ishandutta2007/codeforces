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
vector < int > g[200100];
int u[200100];
int nxt[200100];
int n, q;
void unite(int x, int c){
    if(g[x].size() < g[c].size()) swap(x, c);
    for(int i = 0 ;i < g[c].size(); i++){
        g[x].pb(g[c][i]);
        u[g[c][i]] = x;
    }
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d\n", &n, &q);
    for(int i = 1; i <= n; i++){
        u[i] = i;
        nxt[i] = i;
        g[i].pb(i);
    }
    for(int i = 0, t, l, r; i < q; i++){
        scanf("%d %d %d\n", &t, &l, &r);
        if( t == 1){
            if( u[l] != u[r] ) unite(u[l], u[r]);
        }
        else if(t == 2) {
            while(nxt[l] < r){
                int x = nxt[l] + 1;
                if(u[x] != u[l]) unite(u[x], u[l]);
                nxt[l] = max(nxt[l], nxt[r]);
                l = x;
            }
        }
        else {
            if( u[l] == u[r]){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}