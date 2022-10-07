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


typedef long long ll;
typedef vector < int > vi;

const int maxn = 2e5 + 10;
const int inf = (int)1e9;

vector < int > e[maxn];
vector < int > w[maxn];
vector < int > id[maxn];

long long c[maxn];
int a[maxn];
int b[maxn];
int dir[maxn];
bool use[maxn];

queue < int > q;

int main(){
//     freopen("in", "r", stdin);
 //   freopen("out", "w", stdout);
    int n, m, v, u, ww, j;
    scanf("%d%d", &n, &m);
      
   for(int i = 0; i < m; i++){
        scanf("%d%d%d", &v, &u, &ww); v--; u--;
     
        e[v].pb(u);
        w[v].pb(ww);
        id[v].pb(i);
        
        e[u].pb(v);
        w[u].pb(ww);
        id[u].pb(i);
        
        c[v] -= ww;
        c[u] -= ww;
        a[i] = v;
        b[i] = u;
   }
    
    c[0] = 0;
    c[n - 1] *= 2;
    q.push(0);
    use[0] = 1;

    while(!q.empty()){
        v = q.front();
        q.pop();
//         epr("\t v %d\n", v);
        for(int i = 0; i < (int)e[v].size(); i++){
            u = e[v][i];
            j = id[v][i];
            if (dir[j] == 0){
    dir[j] = (a[j] == v) ? 1 : -1;  
    //epr("dir %d j %d u %d\n", dir[j], j, u);
    c[u] += w[v][i] * 2;
            }    
            //epr("%d u %d\n", (int)c[u], u); 
            assert(c[u] <= 0);
            if (c[u] == 0 && !use[u])
    use[u] = 1, q.push(u);
        }
    }
    for(int i = 0; i < n; i++)
        assert(c[i] == 0);
    
    for(int i = 0; i < m; i++){
        assert(dir[i] != 0);
        printf("%d\n", (dir[i] == 1) ? 0 : 1);
    }
    
    
   
    

    return 0;
}