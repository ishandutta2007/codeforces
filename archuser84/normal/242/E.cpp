//
//   I have a dream and a piano
//
 
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0),cin.tie(0)
#define Loop(x,l,r) for(int x=(l);x<(r);++x)
#define LoopR(x,l,r) for(int x=(r)-1;x>=(l);--x)
typedef std::pair<int,int> pii;
typedef long long ll;
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
 
const int N = 100'010;
int a[N];
 
int main()
{
    FAST;
    int n, m;
    cin >> n;
    Loop(i,0,n) cin >> a[i];
    cin >> m;
    while(m--)
    {
        int t, l, r;
        cin >> t >> l >> r; --l;
        if(t==1)
        {
            ll x = 0;
            if(m&1) Loop(i,l,r) x += a[i];
            else   LoopR(i,l,r) x += a[i];
            cout << x << '\n';
        }
        else
        {
            int x;
            cin >> x;
            if(m&1) Loop(i,l,r) a[i] ^= x;
            else   LoopR(i,l,r) a[i] ^= x;
        }
    }
}