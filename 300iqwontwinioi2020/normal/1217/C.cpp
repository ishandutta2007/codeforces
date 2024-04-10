#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122
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

string S;

int a[N];


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        cin >> S;
        n = (int)S.size();
        S = "#" + S;
        for (int i = 1; i <= n; i++){
            if (S[i] == '1')
                a[i] = 0;
            else
                a[i] = a[i - 1] + 1;
        }
            int ans = 0;
        for (int i = 1; i <= n; i++){
            if (S[i] == '0')
                continue;
            int x = 0;
            int y = a[i - 1] + 1;
            for (int j = i; x <= n && j <= n; j++){
                x = x * 2 + S[j] - '0';
                if (y + j - i >= x)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}