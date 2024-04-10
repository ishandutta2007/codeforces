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

int n;
int a[N];
int x[2][N];

void solve () {
    deque < int > Q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;
    Q.push_back (0);
    for (int i = 1; i <= n; i++){
        while (a[Q.back()] > a[i])
            Q.pop_back();
        x[0][i] = Q.back();
        Q.push_back(i);
    }
    while (Q.size() > 0)
        Q.pop_back();
    a[0] = n+1;
    Q.push_back (0);
    for (int i = 1; i <= n; i++){
        while (a[Q.back()] < a[i])
            Q.pop_back();
        x[1][i] = Q.back();
        Q.push_back(i);
    }
    int ans = 0, cur = n;
    while (cur > 1){
        ans++;
        int t = 0;
        if (x[0][cur] < x[1][cur])
            t = 1;
        int X = x[1-t][cur];
        while (x[t][cur] > X){
            cur = x[t][cur];
        }
    }
    cout << ans << endl;
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