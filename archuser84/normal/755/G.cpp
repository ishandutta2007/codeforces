///
///    "I, Giorno Giovanna, have a dream."
///
///                                    -Giorno Giovanna

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

const int mod = 998244353;
const int lgN = 16;
const int N = 1<<lgN;

typedef array<ll, N> poly;
typedef array<poly, 4> mat;

const int w [24] = {1, 998244352, 911660635, 625715529, 373294451, 827987769, 280333251, 581015842, 628092333, 300892551, 586046298, 615001099, 318017948, 64341522, 106061068, 304605202, 631920086, 857779016, 841431251, 805775211, 390359979, 923521, 961, 31,};
const int wi[24] = {1, 998244352, 86583718, 488723995, 369330050, 543653592, 382946991, 844956623, 91420391, 433414612, 288894979, 260490556, 857007890, 736054570, 474649464, 948509906, 114942468, 962405921, 667573957, 46809892, 304321983, 30429817, 293967900, 128805723,};
int rev[N];

void calc_rev()
{
    Loop(i,0,N)
    {
        int x = i;
        rev[i] = 0;
        Loop(_,0,lgN)
            rev[i] <<= 1,
            rev[i] ^= x&1,
            x >>= 1;
    }
}

void ntt(poly& A, bool inv = 0)
{
    Loop(i,0,N) if(i < rev[i]) swap(A[i], A[rev[i]]);
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

void mmul(mat& a, const mat& b) // both must be tranformed
{
    mat ans;
    Loop(i,0,N) ans[0][i] = (a[0][i]*b[0][i] + a[1][i]*b[2][i]) % mod;
    Loop(i,0,N) ans[1][i] = (a[0][i]*b[1][i] + a[1][i]*b[3][i]) % mod;
    Loop(i,0,N) ans[2][i] = (a[2][i]*b[0][i] + a[3][i]*b[2][i]) % mod;
    Loop(i,0,N) ans[3][i] = (a[2][i]*b[1][i] + a[3][i]*b[3][i]) % mod;
    a = ans;
}

mat I = {};
mat M = {};
poly P[2] = {};

mat matpow(const mat& m, int e) // must be transformed
{
    if(e == 0) return I;
    mat ans = matpow(m, e/2);
    Loop(j,0,4) ntt(ans[j]);
    mmul(ans, ans);
    if(e&1) mmul(ans, m);
    Loop(j,0,4) ntt(ans[j], 1);
    Loop(i,N/2,N) Loop(j,0,4) ans[j][i] = 0;
    return ans;
}

int main()
{
    FAST;
    int n, k;
    cin >> n >> k;
    calc_rev();
    I[0][0] = I[3][0] = M[1][0] = M[2][1] = M[3][0] = M[3][1] = 1;
    P[0][0] = P[1][0] = P[1][1] = 1;
    Loop(j,0,4) ntt(M[j]);
    M = matpow(M, n);
    Loop(j,0,4) ntt(M[j]);
    ntt(P[0]); ntt(P[1]);
    poly ans = {};
    Loop(i,0,N) ans[i] = (M[0][i]*P[0][i] + M[1][i]*P[1][i]) % mod;
    ntt(ans, 1);
    Loop(m,1,k+1) cout << ans[m] << ' ';
}