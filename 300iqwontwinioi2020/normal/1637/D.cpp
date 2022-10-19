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
int a[N], b[N];

bool dp[N*N*2][N];

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i++){
        sum += a[i]+b[i];
        ans += a[i]*a[i]*(n-2);
        ans += b[i]*b[i]*(n-2);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum/2; j >= 0; j--)
            if (dp[j][i-1]){
                dp[j+a[i]][i] = 1;
                dp[j+b[i]][i] = 1;
            }
    for (int i = sum/2; i >= 0; i--)
        if (dp[i][n]){
            cout << ans + i*i + (sum-i)*(sum-i) << endl;
            for (int j = 0; j <= sum; j++)
                for (int cnt = 0; cnt <= n; cnt++)
                    dp[j][cnt] = 0;
            return;
        }
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