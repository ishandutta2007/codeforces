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

int a[N];

void solve () {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i])
            ans = 1;
    }
    if (ans == 0){
        cout << 0 << endl;
        return;
    }
    int l = 1, r = n;
    while (l <= r){
        if (a[l] == 0)
            l++;
        else
            break;
    }
    while (l <= r){
        if (a[r] == 0)
            r--;
        else
            break;
    }
    for (int i = l; i <= r; i++)
        if (a[i] == 0)
            ans = 2;
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