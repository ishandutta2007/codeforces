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

const int maxn = 3e5 + 100;
const int inf = (int)1e9;


vector < int > e[maxn];
bool color[maxn];
int a[maxn];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, v, cnt, u;
    bool flag;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    for(int i = 0; i < n; i++)
        a[i] = i;
   // random_shuffle(a, a + n);
    flag = 1;
    while(flag){
        flag = 0;
        for(int i = 0; i < n; i++){
            cnt = 0;
            v = a[i];
//             epr("v %d\n", v);
            for(int j = 0; j < (int)e[v].size(); j++)
    cnt += color[e[v][j]] ^ color[v] ^ 1;
            
            if (cnt >= 2){
    color[v] ^= 1;
    flag = 1;
            }
        }
        
    }
    for(int i = 0; i < n; i++)
        printf("%d", color[i]);
    
    printf("\n");

    return 0;
}