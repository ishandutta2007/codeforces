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

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")

#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")

#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 1000005, MOD = 1e9 + 7;

int a[N];

void solve () {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int A = a[1], B = a[1];
    for (int i = 1; i <= n; i++){
        A = min (A, a[i]);
        B = max (B, a[i]);
    }
    if (k & 1){
        for (int i = 1; i <= n; i++)
            cout << B - a[i] << " ";
        cout << endl;
    }
    else {
        for (int i = 1; i <= n; i++)
            cout << a[i] - A << " ";
        cout << endl;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}