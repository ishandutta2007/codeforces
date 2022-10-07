#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e9;

vector < int > e[maxn];
bool use[maxn];
int ans[maxn];

int dfs(int v){
  //  epr("%d\n", v);
    use[v] = 1;
    int mask;
    vector < int > b;
    b.resize(26);
    for(int i = 0; i < (int)e[v].size(); i++){
        if (!use[e[v][i]]){
            mask = dfs(e[v][i]);
            for(int j = 0; j < 26; j++)
                if ((mask & (1 << j)) != 0)
                    b[j]++;
        }
    }

    int res = -1;
  //  epr("end %d\n", v);
    for(int i = 25; i >= 0; i--){
        if (b[i] == 0)
            res = i;
        if (b[i] > 1)
            break;
    }
   // epr("res %d\n", res);
    if (res == -1){
        printf("Impossible!\n");
        exit(0);
    }
    mask = 0;
    ans[v] = res;
    b[res] = 1;
    for(int i = 25; i >= res; i--)
        if (b[i] == 1)
            mask = mask | (1 << i);
 //   epr("end end %d\n", v);

    return mask;
}
/*
    for(int i = 0; i < 26; i++)
        if ((mask & (1 << i)) != 0)
            maxpos = i;
    for(int i = 0; i < 26; i++)
        if ((mask & (1 << i)) == 0){
            ans[v] = i;
            if (i > maxpos)
                return (1 << i);
            return mask | (1 << i);
        }
    printf("Impossible!\n");
    exit(0);
}
*/
int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, v, u;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
        printf("%c ", (char)('Z' - ans[i]));
    printf("\n");
   /// for(int i = 0; i < 26; i++)
  //      epr("%c ", 'A' + i);
  //  epr("\n");
    return 0;
}