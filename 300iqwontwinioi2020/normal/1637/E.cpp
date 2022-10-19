#include <bits/stdc++.h>
#define Fr first
#define Sc second
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

const int N = 300005, S = 2000;

map < int, int > M;
map < pair < int, int >, bool > MM;

vector < int > A[S+1];
map < pair < int, int >, bool > F;

void solve () {
    int ans = 0, pas;
    int n, m;
    cin >> n >> m;
    M.clear();
    MM.clear();
    vector < int > V;
    while (n--){
        int x;
        cin >> x;
        if (M[x] == 0)
            V.pb (x);
        M[x]++;
    }
    while (m--){
        int x, y;
        cin >> x >> y;
        MM[{x,y}] = 1;
        MM[{y,x}] = 1;
    }
    for (int x : V){
        if (M[x] <= S){
            A[M[x]].pb (x);
            continue;
        }
        for (int y : V){
            if (x == y)
                continue;
            if (MM[{x,y}])
                continue;
            pas = (x+y)*(M[x]+M[y]);
            ans = max (ans, pas);
        }
    }
    for (int i = 1; i <= S; i++){
        sort (A[i].begin(), A[i].end());
        reverse (A[i].begin(), A[i].end());
    }
    queue < pair < int, int > > Q;
    int x, y, X, Y;
    for (int i = 1; i < S; i++){
        if (A[i].size() == 0)
            continue;
        for (int j = i; j <= S; j++){
            if (A[j].size() == 0)
                continue;
            Q.push ({0, 0});
            F[{0 ,0}] = 1;
            while (Q.size() > 0){
                x = Q.front().Fr;
                y = Q.front().Sc;
                Q.pop();
                F[{x, y}] = 0;
                X = A[i][x];
                Y = A[j][y];
                if (X==Y || MM[{X,Y}]){
                    if (y+1 < A[j].size() && F[{x,y+1}] == 0){
                        Q.push ({x,y+1});
                        F[{x,y+1}] = 1;
                    }
                    if (x+1 < A[i].size() && F[{x+1,y}] == 0){
                        Q.push ({x+1,y});
                        F[{x+1,y}] = 1;
                    }
                    continue;
                }
                pas = (X+Y)*(i+j);
                ans = max (ans, pas);
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= S; i++)
        A[i].clear();
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