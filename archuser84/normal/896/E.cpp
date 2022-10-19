///
///   Let the voice of love take you higher!
///

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
int constexpr N = 100'010;
int a[N];
int n;

int main()
{
    FAST;
    int q;
    cin >> n >> q;
    Loop(i,0,n) cin >> a[i];
    while(q--)
    {
        int t, l, r, x;
        cin >> t >> l >> r >> x; --l;
        if(q&1)
        {
            if(t==1){
                Loop(i,l,r)
                    a[i] = a[i] > x? a[i]-x: a[i];
            }
            if(t==2){
                int ans = 0;
                Loop(i,l,r)
                    ans = a[i] == x? ans+1: ans;
                cout << ans << '\n';
            }
        }
        else
        {
            if(t==1){
                LoopR(i,l,r)
                    a[i] = a[i] > x? a[i]-x: a[i];
            }
            if(t==2){
                int ans = 0;
                LoopR(i,l,r)
                    ans = a[i] == x? ans+1: ans;
                cout << ans << '\n';
            }
        }
    }
}