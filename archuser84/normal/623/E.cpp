///
///    "Yare Yare Daze"
///
///                                    -Jotaro Kujo

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
//#pragma GCC optimize ("O0")

const int K = 65536;
const int mod = 1e9 + 7;
const int nttmod[3] = {113246209, 167772161, 469762049};
const int w[3][30] =
{
    {1, 113246208, 16957016, 1974237, 37507129, 107430771, 82015070, 55823843, 30106475, 98303213, 4783863, 92495845, 104755978, 69898262, 105529541, 27590424, 55031447, 46663013, 24230831, 104889848, 18974736, 4356, 66,},
    {1, 167772160, 65249968, 71493608, 116878283, 150437331, 28504037, 93070217, 32525089, 111106771, 165722578, 28571601, 68062901, 18361612, 108320011, 57880190, 60889090, 145016828, 21720918, 99517537, 88815593, 139583801, 97098840, 83521, 289, 17,},
    {1, 469762048, 19610091, 443138433, 25192837, 67609952, 36137460, 305392217, 386361394, 101133040, 252427090, 339818805, 262760438, 455098209, 448677708, 23379781, 212374678, 115412399, 5642122, 66663606, 415774629, 215869581, 181027852, 312179596, 810000, 900, 30,},
};
const int wi[3][30] =
{
    {1, 113246208, 96289193, 109676743, 39280149, 35204027, 57608229, 494068, 96076777, 69822502, 4992800, 84200987, 2863824, 56321308, 68352186, 3308918, 77290378, 67033954, 73380536, 111929013, 105212253, 110412454, 39464588},
    {1, 167772160, 102522193, 137365239, 127635702, 159924886, 29033016, 34346647, 39291983, 83910258, 22880593, 43312428, 62935641, 107767621, 62073006, 6325839, 65301651, 68148954, 38584908, 76518078, 41109827, 154685058, 65940256, 107164390, 100431086, 29606852},
    {1, 469762048, 450151958, 340060701, 104677229, 200157205, 95870575, 105564117, 342868313, 159812356, 280107213, 207484462, 466236013, 398053006, 304972281, 60372202, 374067518, 91742092, 78333251, 106314473, 212351895, 439594632, 369061327, 19474139, 382508678, 391990332, 15658735},
};
int n, k;

typedef array<ll, K> vec;

int reverse(int x, int n)
{
    int ans = 0;
    while(n--)
    {
        ans <<= 1;
        ans |= x&1;
        x >>= 1;
    }
    return ans;
}

void ntt(int mod, vec& a, bool inverse = 0)
{
    int N = K;
    Loop(i,0,N) if(a[i] >= nttmod[mod]) a[i] %= nttmod[mod];
    int n = __builtin_ctz(N);
    Loop(i, 0, N)
        if(i < reverse(i, n))
            swap(a[i], a[reverse(i, n)]);

    Loop(_, 0, N)
    {
        int M = __builtin_ctz(_+1);
        Loop(m, 1, M+1)
        {
            int r = _+1;
            int l = r-(1<<m);
            int m_2 = (r-l)/2;
            ll wn = (inverse? wi[mod][m]: w[mod][m]), w = 1;
            Loop(i,l,l+m_2)
            {
                ll a1 = (a[i] + w*a[i+m_2]) % nttmod[mod];
                ll a2 = (a[i] - w*a[i+m_2]) % nttmod[mod]; if(a2 < 0) a2 += nttmod[mod];
                if(inverse)
                {
                    a1 = (a1 + (a1&1? nttmod[mod]: 0)) / 2;
                    a2 = (a2 + (a2&1? nttmod[mod]: 0)) / 2;
                }
                a[i] = a1;
                a[i+m_2] = a2;
                w = (w*wn)%nttmod[mod];
            }
        }
    }
}

void mul(int mod, vec& a, vec& b, vec& res)
{
    ntt(mod, a); ntt(mod, b);
    Loop(i,0,K) res[i] = (a[i]*b[i]) % nttmod[mod];
    ntt(mod, res, 1);
    Loop(i,k+1,K) res[i] = 0;
}

template<class T>
T mgcd(T a, T b, T& x, T& y)
{
    T x1 = 1, y1 = 0;
    T x2 = 0, y2 = 1;
    while(b != 0)
    {
        T q = a / b;
        swap(a -= q*b, b);
        swap(x1 -= q*x2, x2);
        swap(y1 -= q*y2, y2);
    }
    x = x1;
    y = y1;
    return a;
}

void chin(vec& v1, vec& v2, vec& v3, vec& res)
{
    Loop(i,0,k+1)
    {
        __int128 a1, a2;
        __int128 m1, m2;
        __int128 n1, n2;
        __int128 x;
        __int128 mod;

        a1 = v1[i], a2 = v2[i];
        n1 = nttmod[0], n2 = nttmod[1];
        mgcd(n1, n2, m1, m2);
        mod = n1*n2;
        x = a1*m2%mod*n2%mod + a2*m1%mod*n1%mod; if(x < 0) x += mod;

        a1 = x, a2 = v3[i];
        n1 = __int128(nttmod[0])*nttmod[1], n2 = nttmod[2];
        mgcd(n1, n2, m1, m2);
        mod = n1*n2;
        x = a1*m2%mod*n2%mod + a2*m1%mod*n1%mod; if(x < 0) x += mod;

        res[i] = x % ::mod;
    }
}

void mul(vec& a, vec& b, vec& res)
{
    vec a2[3], b2[3], r2[3];
    a2[0] = a2[1] = a2[2] = a;
    b2[0] = b2[1] = b2[2] = b;
    mul(0, a2[0], b2[0], r2[0]);
    mul(1, a2[1], b2[1], r2[1]);
    mul(2, a2[2], b2[2], r2[2]);
    chin(r2[0], r2[1], r2[2], res);
    Loop(i,k+1,K) res[i] = 0;
}


ll mpow(ll x, ll e)
{
    ll ans = 1;
    while(e)
    {
        if(e&1) ans = ans*x % mod;
        x = x*x % mod;
        e >>= 1;
    }
    return ans;
}

ll fact[K];
ll pow2[K];
vec F1={};

vec solve(int n)
{
    if(n==1) return F1;
    vec a, b, res;
    a = b = solve(n/2);
    Loop(i,0,k+1) b[i] = b[i]*mpow(pow2[n/2], i) % mod;
    mul(a, b, res);
    if(n&1)
    {
        Loop(i,0,k+1) res[i] = res[i]*mpow(2, i) % mod;
        mul(res, F1, res);
    }
    return res;
}

int main()
{
    FAST;
    cin >> n >> k;
    if(n > k) Kill(0);
    pow2[0] = 1; Loop(i,1,K) pow2[i] = pow2[i-1]*2 % mod;
    fact[0] = 1; Loop(i,1,K) fact[i] = fact[i-1]*i % mod;
    Loop(i,1,k+1) F1[i] = mpow(fact[i], mod-2);
    ll ans = 0;
    vec res = solve(n);
    Loop(i,0,k+1)
    {
        ans += (fact[k]*mpow(fact[k-i], mod-2)%mod)*res[i] % mod;
    }
    ans %= mod;
    cout << ans << '\n';
}