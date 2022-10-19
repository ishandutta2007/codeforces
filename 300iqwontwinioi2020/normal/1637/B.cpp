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

const int N = 105;

int n;
int a[N];
int mex[N][N];
int DP[N][N];
bool F[N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int l = 1; l <= n; l++){
        for (int i = 0; i <= n; i++)
            F[i] = 0;
        for (int r = l; r <= n; r++){
            if (a[r] <= n)
                F[a[r]] = 1;
            mex[l][r] = 0;
            while (F[mex[l][r]])
                mex[l][r]++;
        }
    }
    int ans = 0;
    for (int l = n; l >= 1; l--)
        for (int r = l; r <= n; r++){
            DP[l][r] = mex[l][r] + 1;
            for (int i = l; i < r; i++)
                DP[l][r] = max (DP[l][r], DP[l][i] + mex[i+1][r] + 1);
            ans += DP[l][r];
        }
    cout << ans << endl;
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