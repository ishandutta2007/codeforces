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
#define fr first
#define sc second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 23;
const int maxmask = (1 << 23);
const int inf = (int)1e9;

int a[maxn];
int dp1[maxmask];
int dp2[maxmask];
vector < pair < int, int > >  b[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, ans, newmask;
    bool flag;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = j; k < n; k++)
    if (a[j] + a[k] == a[i])
        b[i].pb(mp(j, k));

/*    for(int i = 0; i < n; i++){
        epr("%d:  ", i);
        for(int j = 0; j < (int)b[i].size(); j++)
            epr("(%d, %d)  ", b[i][j].fr, b[i][j].sc);
        epr("\n");
    }*/
    
    memset(dp1, 63, sizeof(dp1));
    memset(dp2, 63, sizeof(dp2));
    dp1[1] = 1;
    for(int i = 1; i < n; i++){
        for(int mask = 0; mask < (1 << n); mask++)
            if (dp1[mask] < inf){
//  epr("1:\n");
    flag = 0;
    for(int j = 0; j < (int)b[i].size() && !flag; j++)
        if ((mask &  (1 << b[i][j].fr)) && (mask & (1 << b[i][j].sc)))
            flag = 1;
//  epr("flag %d\n", flag);
    if (flag){
        for(int j = 0; j < i; j++)
            if (mask & (1 << j)){
//              epr("2:\n");
                newmask = (mask ^ (1 << j)) ^ (1 << i);
                dp2[newmask] = min(dp1[mask], dp2[newmask]);
            }
        newmask = (mask ^ (1 << i));
        dp2[newmask] = min(dp2[newmask], dp1[mask] + 1);
    }
            }
        memcpy(dp1, dp2, sizeof(dp2));
        memset(dp2, 63, sizeof(dp2));
    }
    ans = -1;
    for(int i = 0; i < (1 << n); i++)
        if (dp1[i] < inf)
            ans = (ans == -1 || ans > dp1[i]) ? dp1[i] : ans;
    
    cout << ans << endl;
    return 0;
}