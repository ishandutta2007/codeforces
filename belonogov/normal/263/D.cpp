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


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = (int)2e5;
const int inf = (int)1e9;
vector < int > edge[maxn];
vector < int > ans;
bool use[maxn];
int b[maxn];
int k;

void dfs(int v){
    int uk = inf;
    use[v] = 1;
//     printf("%d ", v + 1);
    b[v] = ans.size();
    ans.pb(v + 1);
    for(int i = 0; i < (int)edge[v].size(); i++){
        if (!use[edge[v][i]])
            dfs(edge[v][i]);       
        else
            uk = min(uk, b[edge[v][i]]);
    }
    assert((int)ans.size() - uk >= k);
    printf("%d\n", (int)ans.size() - uk);
    for(int i = uk; i < (int)ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
    exit(0);
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, k, x, y;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &x, &y); x--; y--;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    dfs(0);
    

    return 0;
}