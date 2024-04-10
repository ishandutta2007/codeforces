#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 2e5 + 10;
const int inf = (int)1e9;

vector < vector < int > > a;
vector < int > e[maxn];
pair < int, int > b[maxn];
vector < int > ans;
int use[maxn];

void dfs(int v){
    use[v] = 1;
    for(int i = 0; i < (int)e[v].size(); i++){
        if (use[e[v][i]] == 1){
            cout << "-1\n";
            exit(0);
        }
        if (use[e[v][i]] == 0)
            dfs(e[v][i]);
    }
    ans.pb(v);
    use[v] = 2;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, uk, free, l, p;
    scanf("%d%d", &n, &m);
    a.resize(n);
    for(int i = 0; i < n; i++){
        a[i].resize(m);
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    free = m;
    for(int i = 0; i < n; i++){
        uk = 0;
        for(int j = 0; j < m; j++)
            if (a[i][j] != -1)
    b[uk++] = mp(a[i][j], j); 
        sort(b, b + uk);
        l = 0;
        p = -1;
        for(int j = 0; j < uk; j++){
            if (p != -1) e[p].pb(b[j].ss);
            if (j + 1 != uk && b[j + 1].ff > b[j].ff){
    p = free++;
    for(int k = l; k < j + 1; k++)
        e[b[k].ss].pb(p);
    l = j + 1;
            }
        }
    }
//     for(int i = 0; i < free; i++){
//         epr("%d :   ", i);
//         for(int j = 0; j < (int)e[i].size(); j++)
//             epr("%d ", e[i][j]);
//         epr("\n");
//     }
//     epr("free %d\n", free);
    for(int i = 0; i < free; i++)
        if (use[i] == 0)
            dfs(i);
  /*  for(int i = 0; i < (int)ans.size(); i++)
        epr("%d ", ans[i]);
    epr("\n\n\n");
  */      
    for(int i = (int)ans.size() - 1; i >= 0; i--)
        if (ans[i] < m)
            printf("%d ", ans[i] + 1);
    printf("\n");
    
        
    return 0;
}