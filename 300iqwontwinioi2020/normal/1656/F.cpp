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


int a[N], b[N], c[N];

bool check (int X){
    double r = -INF, l = INF;
    for (int i = 1; i < n; i++){
        if (b[i] == 0 && c[i] <= X)
            return 1;
        if (b[i] == 0)
            continue;
        if (b[i] > 0)
            r = max (r, (double)(X - c[i])/b[i]);
        else
            l = min (l, (double)(-X + c[i])/(-b[i]));
    }
    if (l <= r)
        return 1;
    return 0;
}


void solve () {
    cin >> n;
    int S = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        S += a[i];
    }
    sort (a+1,a+n+1);
    if (S + a[1]*(n-2) > 0){
        cout << "INF" << endl;
        return;
    }
    if (S + a[n]*(n-2) < 0){
        cout << "INF" << endl;
        return;
    }
    reverse (a+2,a+n);
    b[1] = a[n] * (n-2) + S;
    c[1] = a[n] * (S - a[n]);
    for (int i = 2; i <= n; i++){
        b[i] = b[i-1] - (a[n] - a[1]);
        c[i] = c[i-1] - a[i] * (a[n] - a[1]);
        //cout << b[i] << " " << c[i] << endl;
    }
    int L = -INF, R = INF;
    while (L < R){
        int MID = L + R >> 1;
        if (check (MID))
            R = MID;
        else
            L = MID + 1;
    }
    if (L == INF)
        cout << "INF" << endl;
    else
        cout << L << endl;
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