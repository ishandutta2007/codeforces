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

const int N = 300005, MOD = 1e9 + 7, INF = 1e18;


pair < int, int > P[N];
int a[N], ans[N];

int fix[N];
vector < int > V[N];

void solve () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        P[i] = {a[i], i};
    }
    sort (P+1, P+n+1);
    for (int i = 1; i <= n; i++){
        fix[P[i].F]++;
        V[fix[P[i].F]].pb (P[i].S);
    }
    for (int m,i = 1; i <= n; i++){
        m = (int)V[i].size();
        if (m == 0)
            continue;
        for (int j = 0; j < m-1; j++)
            ans[V[i][j]] = a[V[i][j+1]];
        ans[V[i].back()] = a[V[i][0]];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++){
        fix[i] = 0;
        V[i].clear();
    }
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