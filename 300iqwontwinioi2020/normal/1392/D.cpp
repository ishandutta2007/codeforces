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

string S;


void solve () {
    int n, ans = 0;
    cin >> n >> S;
    if (n <= 2){
        cout << 0 << endl;
        return;
    }
    vector < int > V;
    S = "#" + S;
    int cnt = 1;
    for (int i = 2; i <= n; i++){
        if (S[i] == S[i-1]){
            cnt++;
            continue;
        }
        V.pb (cnt);
        cnt = 1;
    }
    if (V.size() == 0 || S[1] != S[n])
        V.pb (cnt);
    else
        V[0] += cnt;
    for (int x : V)
        ans += x / 3;
    if (V.size() == 1){
        ans = (V[0] + 2) / 3;
    }
    cout << ans << endl;
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