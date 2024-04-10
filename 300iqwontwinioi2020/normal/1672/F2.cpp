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


vector < int > V;
bool F[N];
vector < int > g[N];

void dfs (int k){
    F[k] = 1;
    for (int to : g[k]){
        if (F[to] == 0)
            dfs (to);
    }
    V.pb (k);
}


int a[N], b[N];

int fix[N], fx[N];
int ind[N];


void solve () {
    int n;
    cin >> n;
    V.clear();
            for (int i = 1; i <= n; i++){
                fix[i] = fx[i] = ind[i] = F[i] = 0;
                g[i].clear();
            }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        fix[a[i]]++;
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (a[i] != b[i])
            fx[a[i]]++;
    }
    int x = 1;
    for (int i = 2; i <= n; i++)
        if (fix[i] > fix[x])
            x = i;
    /*for (int i = 1; i <= n; i++)
        if (fx[i] == fix[x])
            x = i;
    if (fx[x] != fix[x]){
        cout << "WA" << endl;
        return;
    }*/
    for (int i = 1; i <= n; i++){
        if (a[i] == x || b[i] == x)
            continue;
        g[a[i]].pb (b[i]);
    }
    for (int i = 1; i <= n; i++)
        if (F[i] == 0)
            dfs (i);
    for (int i = 0; i < n; i++)
        ind[V[i]] = i+1;
    for (int i = 1; i <= n; i++){
        if (a[i] == x || b[i] == x)
            continue;
        if (ind[a[i]] <= ind[b[i]]){
            cout << "WA" << endl;

            return;
        }
    }
    cout << "AC" << endl;
    V.clear();
    for (int i = 1; i <= n; i++){
        fix[i] = fx[i] = ind[i] = F[i] = 0;
        g[i].clear();
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