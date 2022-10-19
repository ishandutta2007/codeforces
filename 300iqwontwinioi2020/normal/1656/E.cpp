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
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

//#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 300005, MOD = 1e9 + 7, INF = 1e11;

int n;

vector < int > g[N];

int a[N];

void dfs (int k, int p){
    a[k] = (a[p]^1);
    for (int to : g[k]){
        if (to == p)
            continue;
        dfs (to, k);
    }
}

void solve () {
    cin >> n;
    for (int u,v,i = 1; i < n; i++){
        cin >> u >> v;
        g[u].pb (v);
        g[v].pb (u);
    }
    dfs (1, 0);
    for (int x,i = 1; i <= n; i++){
        x = (int)g[i].size();
        if (a[i])
            cout << x << " ";
        else
            cout << -x << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
        g[i].clear();
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}