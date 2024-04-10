///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

const int N = 100'010;
const int inf = 1e9 + 10;
int a[N];
int b[N];

int main()
{
    FAST;
    int q;
    cin >> q;
    fill(a, a+N, inf);
    fill(b, b+N, inf);
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            if(k < 0){
                k = -k;
                Loop(i,l,r) if(b[i] > k) b[i] = k;
            }
            else
                Loop(i,l,r) if(a[i] > k) a[i] = k;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ll ans = 0;
            Loop(i,l,r)
                if(a[i] != inf && b[i] != inf) ans += a[i] + b[i];
            cout << ans << '\n';
        }
    }
}