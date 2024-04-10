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
//#define F first
//#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int mod = 998'244'353;
const int W[24] = {1, 998244352, 911660635, 625715529, 373294451, 827987769, 280333251, 581015842, 628092333, 300892551, 586046298, 615001099, 318017948, 64341522, 106061068, 304605202, 631920086, 857779016, 841431251, 805775211, 390359979, 923521, 961, 31,};

typedef vector<ll> vec;

template<class T>
void print(vector<T>& a)
{
    for(T x : a)
        cerr << x << ' ';
    cerr << '\n';
}

ll mod_pow(ll x, ll e, int mod)
{
    ll ans = 1;
    for(; e; e >>= 1)
    {
        if(e & 1)
            ans = ans*x % mod;
        x = x*x % mod;
    }
    return ans;
}

int reverse(int i, int logn)
{
    int ans = 0;
    for(; logn; --logn)
    {
        ans <<= 1;
        ans |= i&1;
        i >>= 1;
    }
    return ans;
}

void fft(vec& a, bool inverse = 0, int offset = 0, int jump = 1)
{
    int n = a.size();
    int logn = 31-__builtin_clz(n);
    Loop(i,0,n)
    {
        if(i < reverse(i, logn))
            swap(a[i], a[reverse(i, logn)]);
    }

    Loop(r,1,n+1)
    {
        int Z = __builtin_ctz(r);
        Loop(z,1,Z+1)
        {
            int l = r - (1 << z);
            int m = r-l;
            int m_2 = m/2;
            ll w = 1, wn = W[z];
            if(inverse) wn = mod_pow(wn, mod-2, mod);
            Loop(j,l,l+m_2)
            {
                int j2 = j + m_2;
                ll a0 = a[j], a1 = a[j2];
                a[j] = (a0 + w*a1) % mod;
                a[j2] = (a0 - w*a1 + mod) % mod;
                w = (w*wn) % mod;
                if(inverse){
                    a[j] = (mod*(a[j]&1)+a[j])/2;
                    a[j2] = (mod*(a[j2]&1)+a[j2])/2;
                }
            }
        }
    }
}

void mul(vec& a, vec b)
{
    int n = a.size() + b.size() - 1;
    int logn = 31 - __builtin_clz(n);
    if(n != (1 << logn))
       n = (2 << logn);
    a.resize(n); b.resize(n);
    fft(a); fft(b);
    Loop(i,0,n)
        a[i] = a[i] * b[i] % mod;
    fft(a,1);
}

vec k1(10);
vec ansv = {1};
void solve(int n)
{
    for(; n; n >>= 1)
    {
        if(n & 1)
           mul(ansv, k1);
        mul(k1, k1);
    }
}



int main()
{
    FAST;
    int n, k;
    cin >> n >> k; n >>= 1;
    Loop(i,0,k)
    {
        int x;
        cin >> x;
        k1[x] = 1;
    }
    solve(n);
    ll ans = 0;
    for(auto x : ansv)
    {
        ans += x*x;
        ans %= mod;
    }
    cout << ans << '\n';
}