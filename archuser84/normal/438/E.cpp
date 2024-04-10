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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int lgN = 17;
const int N = 1<<lgN;
const int mod = 998244353;
typedef vector<ll> vec;

ll mpow(ll a, ll b)
{
    if(!b) return 1;
    ll ans = mpow(a, b>>1);
    ans = ans*ans % mod;
    if(b&1) ans = ans*a % mod;
    return ans;
}

ll w[24], wi[24];
void calcw()
{
    w[23] = 31; wi[23] = mpow(31, mod-2);
    LoopR(i,0,23)
        w [i] = w [i+1]*w [i+1] % mod,
        wi[i] = wi[i+1]*wi[i+1] % mod;
}

void fft(vec& A, bool inv = 0)
{
    static auto rev = [](int x, int n)
    {
        int ans = 0;
        while(n--)
            ans <<= 1,
            ans ^= x&1,
            x >>= 1;
        return ans;
    };
    int N = A.size();
    int lgN = __builtin_ctz(N);
    Loop(i,0,N) if(i < rev(i, lgN)) swap(A[i], A[rev(i, lgN)]);
    Loop(r,1,N+1)
    {
        int lgM = __builtin_ctz(r);
        Loop(lgm, 0, lgM)
        {
            int m = 1<<lgm;
            int l = r-2*m;
            ll wn = inv? wi[lgm+1]: w[lgm+1];
            ll w = 1;
            Loop(i,l,r-m)
            {
                ll a1 = (A[i] + w*A[i+m]) % mod;
                ll a2 = (A[i] + (mod-w)*A[i+m]) % mod;
                if(inv)
                {
                    a1 = a1&1? (a1+mod)>>1: a1>>1;
                    a2 = a2&1? (a2+mod)>>1: a2>>1;
                }
                A[i] = a1;
                A[i+m] = a2;
                w = w*wn % mod;
            }
        }
    }
}

void mul(vec& a, vec& b)
{
    int n = a.size();

    a.resize(n<<1);
    b.resize(n<<1);
                 fft(a);
    if(&a != &b) fft(b);

    Loop(i,0,a.size()) a[i] = a[i]*b[i] % mod;

                 fft(a, 1);
    if(&a != &b) fft(b, 1);
    a.resize(n);
    b.resize(n);
}

void inv(vec& a)
{
    int n = a.size();
    if(n == 1) {a[0] = mpow(a[0], mod-2); return;}
    int m = n>>1;
    vec L, H, P = a;
    a.resize(m); inv(a);
    H = P;
    L = a; L.resize(n);
    mul(H, L);
    mul(H, L);
    a.resize(n); Loop(i,m,n) a[i] = (L[i]+mod-H[i]) % mod;
}

void sqrt(vec& a)
{
    static const ll i2 = (mod+1)>>1;
    int n = a.size();
    if(n == 1) {a[0] = sqrt(a[0]); return;}
    vec L, H, P = a;
    int m = n>>1;
    a.resize(m); sqrt(a);
    L = a; L.resize(n);
    H = L;
    mul(H, L);
    Loop(i,0,n) H[i] = (P[i] + mod - H[i])*i2 % mod;
    inv(L);
    mul(H, L);
    a.resize(n); Loop(i,m,n) a[i] = H[i];
}

vec C(N);
vec F(N);
int n, m;

int main()
{
    calcw();
    FAST;
    cin >> n >> m;
    while(n--)
    {
        int x;
        cin >> x;
        C[x]++;
    }
    Loop(i,0,N) F[i] = (mod-4)*C[i] % mod;
    F[0] = (F[0]+1)%mod;
    sqrt(F);
    F[0] = (F[0]+1)%mod;
    inv(F);
    Loop(i,0,N) F[i] = 2*F[i] % mod;
    Loop(i,1,m+1) cout << F[i] << '\n';
}