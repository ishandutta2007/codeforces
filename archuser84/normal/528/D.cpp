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
const int w [24] = {1, 998244352, 911660635, 625715529, 373294451, 827987769, 280333251, 581015842, 628092333, 300892551, 586046298, 615001099, 318017948, 64341522, 106061068, 304605202, 631920086, 857779016, 841431251, 805775211, 390359979, 923521, 961, 31,};
const int wi[24] = {1, 998244352, 86583718, 488723995, 369330050, 543653592, 382946991, 844956623, 91420391, 433414612, 288894979, 260490556, 857007890, 736054570, 474649464, 948509906, 114942468, 962405921, 667573957, 46809892, 304321983, 30429817, 293967900, 128805723,};
const int N = 1<<19;

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

void fft(ll* a, bool inverse = 0)
{
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

int mp(char c)
{
    switch(c)
    {
        case 'A': return 0;
        case 'T': return 1;
        case 'C': return 2;
        case 'G': return 3;
    }
    return -1;
}

string s, t;
ll si[4][N];
ll ti[4][N];
int n, m, k;

int main()
{
    FAST;
    cin >> n >> m >> k;
    cin >> s >> t;
    int mx[4];
    Loop(i,0,4) mx[i] = -N;
    Loop(i,0,n)
    {
        mx[mp(s[i])] = i;
        Loop(j,0,4) if(i - mx[j] <= k) si[j][i] = 1;
    }
    Loop(i,0,4) mx[i] = N;
    LoopR(i,0,n)
    {
        mx[mp(s[i])] = i;
        Loop(j,0,4) if(mx[j] - i <= k) si[j][i] = 1;
    }
    Loop(i,0,m) ti[mp(t[i])][(N-i)%N] = 1;
    Loop(i,0,4){
        fft(si[i]);
        fft(ti[i]);
        Loop(j,0,N) si[i][j] = (si[i][j]*ti[i][j] % mod);
        fft(si[i], 1);
    }
    int ans = 0;
    Loop(i,0,N) ans += (si[0][i] + si[1][i] + si[2][i] + si[3][i] == m);
    cout << ans << '\n';
}