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

const int N = 500005, MOD = 1e9 + 7, INF = 1e18;

int POWER (int x, int y){
    int ans = 1;
    while (y){
        if (y&1)
            ans = ans * x % MOD;
        y >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

int n;
int a[N];
int F[N], inv[N];

int C (int x, int y){
    return F[x] * inv[y] % MOD * inv[x-y] % MOD;
}

void solve () {
    cin >> n;n++;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    F[0] = inv[0] = 1;
    for (int i = 1; i < N; i++){
        F[i] = F[i-1] * i % MOD;
        inv[i] = POWER (F[i], MOD - 2);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (a[i])
        ans += C (i+a[i]-1, i);
        ans %= MOD;
    }
    cout << ans << endl;
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    //cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}