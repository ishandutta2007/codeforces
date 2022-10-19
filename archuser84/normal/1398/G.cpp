#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'020;
const int mod = 7*17*(1 << 23) + 1;

ll my_pow(ll x, ll e, int mod)
{
    ll ans = 1;
    for(; e; e >>= 1)
    {
        if(e&1)
            ans = (ans*x)%mod;
        x = (x*x)%mod;
    }
    return ans;
}

const int w [24] = {1, 998244352, 911660635, 625715529, 373294451, 827987769, 280333251, 581015842, 628092333, 300892551, 586046298, 615001099, 318017948, 64341522, 106061068, 304605202, 631920086, 857779016, 841431251, 805775211, 390359979, 923521, 961, 31,};
const int wi[24] = {1, 998244352, 86583718, 488723995, 369330050, 543653592, 382946991, 844956623, 91420391, 433414612, 288894979, 260490556, 857007890, 736054570, 474649464, 948509906, 114942468, 962405921, 667573957, 46809892, 304321983, 30429817, 293967900, 128805723,};

typedef vector<ll> vec;

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

void fft(vec& a, bool inverse = 0)
{
    int N = a.size();
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
            ll wn = (inverse? wi[m]: w[m]), w = 1;
            Loop(i,l,l+m_2)
            {
                ll a1 =  (a[i] + w*a[i+m_2]) % mod;
                ll a2 = ((a[i] - w*a[i+m_2]) % mod + mod) % mod;
                if(inverse)
                {
                    a1 = (a1 + (a1&1? mod: 0)) / 2;
                    a2 = (a2 + (a2&1? mod: 0)) / 2;
                }
                a[i] = a1;
                a[i+m_2] = a2;
                w = (w*wn)%mod;
            }
        }
    }
}

void mul(vec& a, vec& b, vec& res)
{
    int N = a.size() + b.size();
    int n = 31 - __builtin_clz(N);
    N = 2 << n;
    a.resize(N);
    b.resize(N);
    res.resize(N);
    fft(a); fft(b);
    Loop(i,0,N)
        res[i] = (a[i]*b[i]) % mod;
    fft(res, 1);
}

int n, x, y;
vec a(2*N), b(2*N), res;

int find_ans(int k)
{
    if(k&1)
        return -1;
    k /= 2;
    int ans = -1;
    for(int d = 1; d*d <= k; ++d)
    {
        if(k%d)
            continue;
        if(d > y && res[2*N+d-y])
            ans = max(ans, 2*d);
        d = k/d;
        if(d > y && res[2*N+d-y])
            ans = max(ans, 2*d);
        d = k/d;
    }
    return ans;
}

int main()
{
    FAST;
    cin >> n >> x >> y;
    Loop(i,0,n+1)
    {
        int k;
        cin >> k;
        a[N+k] = 1;
        b[N-k] = 1;
    }
    mul(a, b, res);
    int q;
    cin >> q;
    while(q--)
    {
        int k;
        cin >> k;
        cout << find_ans(k) << ' ';
    }
}