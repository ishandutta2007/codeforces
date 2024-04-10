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

const int maxn = 1e5 + 10;
const int inf = (int)1e9;

struct ret{
    long long p, m;
    ret(){p = m = 0;}
    ret(long long p, long long m): p(p), m(m){};
};

vector < int > e[maxn];
bool use[maxn];
long long a[maxn];

ret dfs(int v){
    use[v] = 1;
    ret ans, res;
    for(int i = 0; i < (int)e[v].size(); i++)
        if (!use[e[v][i]]){
            res = dfs(e[v][i]);
            ans = ret(max(ans.p, res.p), max(ans.m, res.m));
        }
    long long val = a[v] + ans.p - ans.m;
    if (val > 0)
        ans.m += val;
    else
        ans.p += -val;
    return ans;
}



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, x, v, u;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a[i] = x;
    }
    ret res;
    res = dfs(0);
    cout << res.m + res.p << endl;
    return 0;
}