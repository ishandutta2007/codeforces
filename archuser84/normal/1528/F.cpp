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
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

const int mod = 998244353;
const int N = 262144;
const int lgN = 18;
ll w[24];
ll wi[24];

ll mpow(ll x, ll y)
{
    ll ans = 1;
    while(y)
    {
        if(y&1) ans = ans*x % mod;
        x = x*x % mod;
        y >>= 1;
    }
    return ans;
}

void calc()
{
    w[23] = 31; wi[23] = mpow(31, mod-2);
    LoopR(i,0,23)
        w[i] = w[i+1]*w[i+1] % mod,
        wi[i] = wi[i+1]*wi[i+1] % mod;
}

typedef array<ll, N> ply;

void fft(ply& A, bool inv)
{
    static auto rev = [](int x) {
        int y = 0;
        Loop(_,0,lgN)
            y <<= 1,
            y ^= x&1,
            x >>= 1;
        return y;
    };
    Loop(i,0,N) if(i < rev(i)) swap(A[i], A[rev(i)]);
    Loop(r,1,N+1)
    {
        int lg = __builtin_ctz(r);
        Loop(k,0,lg)
        {
            int l = r-(2<<k);
            int m = (l+r)/2;
            ll wn = inv? wi[k+1]: w[k+1];
            ll w = 1;
            Loop(i,0,1<<k)
            {
                ll x = (A[l+i] + w*A[m+i]) % mod;
                ll y = (A[l+i] - w*A[m+i]) % mod; if(y < 0) y += mod;
                A[l+i] = x;
                A[m+i] = y;
                w = w*wn % mod;
            }
        }
    }
    if(inv) Loop(i,0,N) A[i] = A[i]*mpow(1<<lgN, mod-2) % mod;
}


int n, k;
ply P, Q;
// sigma i=1 to min(n, k) C(n, i)*magic[k][i]*(n+1)^(n-i)
// magic[k][z] =    sigma i=0 to k C(z, i)*(-1)^i*(z-i)^k
//             = z!*sigma i=0 to k ((-1)^i/i!) * ((z-i)^k/(z-i)!)

int main()
{
    FAST
    calc();
    cin >> n >> k;
    ll fct;
    fct = 1; Loop(z,0,k+1) P[z] = z&1? mpow(mod-fct, mod-2): mpow(fct, mod-2), fct = fct*(z+1) % mod;
    fct = 1; Loop(z,0,k+1) Q[z] = mpow(z, k)*mpow(fct, mod-2), fct = fct*(z+1) % mod;
    fft(P, 0); fft(Q, 0);
    Loop(z,0,N) P[z] = P[z]*Q[z]%mod;
    fft(P, 1);
    fct = 1; Loop(z,0,k+1) P[z] = P[z]*fct%mod, fct = fct*(z+1) % mod;
    ll ans = 0;
    ll C = 1;
    Loop(i,0,min(n,k)+1) ans += C*P[i]%mod*mpow(n+1,n-i)%mod, C = C*(n-i)%mod*mpow(i+1,mod-2)%mod;
    ans %= mod;
    cout << ans << '\n';
}