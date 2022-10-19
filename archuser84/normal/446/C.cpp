///
///    I have a dream and a piano
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
 
#pragma GCC optimize("O3")
#pragma GCC target("avx")
 
const int N = 300'010;
const int S = 500;
const int mod = 1e9 + 9;
int a[N];
ll aa[N];
int b[N];
int f[N];
int n, q;
int qt[N],ql[N],qr[N];
 
int main()
{
    FAST;
    cin >> n >> q;
    Loop(i,0,n) cin >> a[i], aa[i+1]=aa[i]+a[i];
    f[1]=1; Loop(i,2,N) f[i]=(f[i-2]+f[i-1])%mod;
    for(int j = 0; j < q; j+=S)
    {
        for(int i = j; i < j+S && i < q; ++i)
        {
            int t,l,r;
            cin>>t>>l>>r;--l;
            qt[i]=t;ql[i]=l;qr[i]=r;
            if(t == 1){
                b[l]=(b[l]+f[1])%mod;
                b[r]=(mod-f[r-l+1]+b[r])%mod;
                b[r+1]=(mod-f[r-l]+b[r+1])%mod;
            } else {
                ll ans = (aa[r]-aa[l])%mod;
                Loop(k,j,i)
                {
                    if(qt[k] == 2) continue;
                    int L = max(l,ql[k]);
                    int R = min(r,qr[k]);
                    if(L >= R) continue;
                    ans += f[R-ql[k]+2]-1;
                    ans -= f[L-ql[k]+2]-1;
                }
                ans = (ans%mod+mod)%mod;
                cout << ans << '\n';
            }
        }
        a[0] = (a[0]+b[0])%mod;
        b[1] = (b[1]+b[0])%mod;
        a[1] = (a[1]+b[1])%mod;
        Loop(i,2,n)
        {
            b[i] = b[i]+b[i-1]>=mod?b[i]+b[i-1]-mod:b[i]+b[i-1];
            b[i] = b[i]+b[i-2]>=mod?b[i]+b[i-2]-mod:b[i]+b[i-2];
            a[i] = a[i]+b[i]>=mod?a[i]+b[i]-mod:a[i]+b[i];
        }
        Loop(i,0,n) b[i] = 0;
        Loop(i,0,n) aa[i+1] = aa[i]+a[i];
    }
}