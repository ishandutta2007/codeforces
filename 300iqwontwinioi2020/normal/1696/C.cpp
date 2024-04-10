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

int n, m, k;

void solve () {
    deque < pair < int, int > > Q, q;
    cin >> n >> m;
    for (int x, y, i = 1; i <= n; i++){
        cin >> x;
        y = 1;
        while (x % m == 0){
            x /= m;
            y *= m;
        }
        if (Q.size() == 0){
            Q.push_back({x,y});
            continue;
        }
        if (Q.back().F == x){
            Q.back().S += y;
        }
        else
            Q.push_back({x,y});
    }
    cin >> k;
    for (int x, y, i = 1; i <= k; i++){
        cin >> x;
        y = 1;
        while (x % m == 0){
            x /= m;
            y *= m;
        }
        if (q.size() == 0){
            q.push_back({x,y});
            continue;
        }
        if (q.back().F == x){
            q.back().S += y;
        }
        else
            q.push_back({x,y});
    }
    if ((int)Q.size() != (int)q.size()){
        cout << "No" << endl;
        return;
    }
    while (Q.size() > 0){
        if (Q.back() != q.back()){
            cout << "No" << endl;
            return;
        }
        Q.pop_back();
        q.pop_back();
    }
    cout << "Yes" << endl;
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