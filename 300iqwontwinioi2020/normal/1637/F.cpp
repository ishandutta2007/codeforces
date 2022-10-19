#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define int long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#pragma GCC optimize ("O3")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 200005, INF = 1e17;

int n;
int a[N], b[N];
vector < int > g[N];

int DP[N];
int ans;

void dfs (int k, int p){
    pair < int, int > x,y,z;
    x = y = {0, 0};
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
        z = {a[to], to};
        if (z > y)
            y = z;
        if (y > x)
            swap (x, y);
    }
    int du = DP[x.S];
    if (a[k] > x.F)
        ans += a[k] - x.F;
    if (a[k] > x.F){
        DP[k] += a[k] - y.F;
    }
    else if (a[k] > y.F){
        DP[k] += min (max (a[k],b[x.S]) - y.F, a[k] - y.F + du);
    }
    else {
        DP[k] += min (max (y.F,b[x.S]) - y.F, du);
    }
    b[k] = a[k];
    if (x.F == y.F){
        if (y.F >= a[k])
            b[k] = 0;
    }
    else
        b[k] = max (a[k], b[x.S]);
    a[k] = max (a[k], x.F);
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int u,v,i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    int id = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[id])
            id = i;
    //id=1;
    dfs (id, 0);
    cout << ans+DP[id] << endl;
    //for (int i = 1; i <= n; i++)cout << DP[i] << " " << a[i] << endl;
    ans = 0;
    for (int i = 1; i <= n; i++){
        g[i].clear();
        DP[i] = a[i] = 0;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin >> T;
    while (T--){
        solve ();
    }
}
/*
9
68546702 71582332 671255574 470021948 52032131 311401753 825767059 216879205 648690127
1 2
2 3
3 4
3 5
5 6
3 7
5 8
8 9

5
1 1 10 10 10
1 2
2 3
3 4
3 5


10
722349051 10986040 366747062 827862934 933990134 779079809 959846254 575075189 837614476 211940198
1 2
1 3
3 4
4 5
2 6
4 7
1 8
5 9
7 10

9
68546702 71582332 671255574 470021948 52032131 311401753 825767059 216879205 648690127
1 2
2 3
3 4
3 5
5 6
3 7
5 8
8 9
*/