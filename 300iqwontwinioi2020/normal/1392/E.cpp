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

int n;
int a[30][30];
int B[66];

void solve () {
    int S;
    cin >> S;
    int x = 1, y = 1;
    cout << x << " " << y << endl;
    for (int i = 1; i <= n*2-2; i++){
        if (S % 2 == 0){
            if (x % 2 == 0)
                x++;
            else
                y++;
        }
        else {
            if (x % 2 == 0)
                y++;
            else
                x++;
        }
        S /= 2;
        cout << x << " " << y << endl;
    }
}

main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    B[0] = 1;
    for (int i = 1; i <= 55; i++)
        B[i] = B[i-1] * 2;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            if (i % 2 == 0)
                a[i][j] = B[i+j-3];
            else
                a[i][j] = 0;
        }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        solve ();
    }
}