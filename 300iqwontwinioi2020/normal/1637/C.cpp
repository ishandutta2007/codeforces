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

const int N = 100005;

int n;
int a[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ok = 0, cnt = 0, OK = 0;
    int ans = 0;
    for (int i = 2; i < n; i++){
        ans += a[i]/2;
        cnt += a[i]%2;
        if (a[i] >= 2)
            ok++;
        if (a[i] >= 2 && a[i]%2==0)
            OK++;
    }
    if (cnt == 0){
        cout << ans << endl;
        return;
    }
    if (ok == 0){
        cout << -1 << endl;
        return;
    }
    if (OK == 0 && ok == 1 && n==3){
        cout << -1 << endl;
        return;
    }
    cout << ans+cnt << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve ();
    }
}