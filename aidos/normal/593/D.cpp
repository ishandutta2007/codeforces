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
const int maxn = (int) 4e5 + 10;

using namespace std;

vector < ll > g[maxn];
vector < pll > t[maxn];
vector < int > gg[maxn];
int pos[maxn];
int ind[maxn];
int pp[21][maxn];
int h[maxn];
int a[maxn];
int n;
int len[maxn];

map < pii, ll > mm;
pii xx[maxn];
ll cc[maxn];

int sz = 0;

void dfs(int v, int p = 0){
    pp[0][v] = p;
    for(int i = 1; i < 20; i++){
        pp[i][v] = pp[i-1][pp[i-1][v]];
    }
    h[v] = h[p] + 1;
    ind[v] = mm[mp(v, p)];
    pos[v] = v;
    for(int i = 0; i < gg[v].size(); i++){
        int to = gg[v][i];
        if( to == p) continue;
        dfs(to, v);
    }
}


int LCA(int a, int b){
    if(h[a] < h[b] ) swap(a,b);
    for(int i = 19; i >= 0; i--){
        if(pp[i][a] != 0 && h[a] - (1 << i)  >= h[b]) a = pp[i][a];
    }
    if( a== b) return b;
    for(int i = 19; i >= 0; i--){
        if(pp[i][a] != pp[i][b]){
            a = pp[i][a];
            b = pp[i][b];
        }
    }
    return pp[0][a];
}

int get(int a){
    if( cc[ind[pos[a]]] > 1 ) return pos[a];
    if(pos[a] == a) return pos[a] = get(pp[0][a]);
    return pos[a] = get(pos[a]);    
}


ll query(int b, int c, ll val){
    int lca = LCA(b, c);
    while(h[b] > h[lca] && val > 0){
        b=get(b);
        if(h[b] <= h[lca]) break;
        val /= cc[ind[b]];
        b = pp[0][b];
    }                 
    while(h[c] > h[lca] && val > 0){
        c=get(c);
        if(h[c] <= h[lca]) break;
        val/=cc[ind[c]];
        c = pp[0][c];
    }
    
    return val;
}



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);                                
    #endif

    int m;
    scanf("%d %d", &n, &m);
    for(int i = 2; i <= n; i++){
        int a, b;
        ll c;
        scanf("%d %d %I64d", &a, &b, &c);
        gg[a].pb(b);
        gg[b].pb(a);
        mm[mp(a, b)] = i-1;
        mm[mp(b, a)] = i-1;
        xx[i-1] = mp(a, b);
        cc[i-1] = c;
    }
    cc[0]=2;
    dfs(1, 0);
    int ty, a, b;
    ll x, gt;

    for(int i = 0; i < m; i++){
        
        scanf("%d %d ", &ty, &a);
        if( ty == 1){
            scanf("%d %I64d", &b, &x);
            gt = query(a, b, x);
            printf("%I64d\n", gt);
        }
        else {
            scanf("%I64d ", &x);
            cc[a] = x;
        }
    }


    
    


     
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}