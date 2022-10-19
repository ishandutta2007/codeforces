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

int n, k;
int a[N];
map < int, int > M;

void solve () {
    cin >> n >> k;
    M.clear();
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        M[a[i]]++;
    }
    int mex = 0, cnt = k;
    while (mex < n){
        if (M[mex]){
            mex++;
            continue;
        }
        if (cnt == 0)
            break;
        cnt--;
        mex++;
    }
    set < pair < int, int > > A;
    for (int i = 1; i <= n; i++)
        if (a[i] > mex)
            A.insert ({M[a[i]], a[i]});
    cnt = k;
    while (A.size() > 0){
        auto it = A.begin();
        if ((*it).F <= cnt){
            cnt -= (*it).F;
            A.erase (it);
        }
        else
            break;
    }
    cout << (int)A.size() << endl;
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