///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 7*17*(1<<23)+1;
const int N = 1<<19;

const int w [24] = {1, 998244352, 911660635, 625715529, 373294451, 827987769, 280333251, 581015842, 628092333, 300892551, 586046298, 615001099, 318017948, 64341522, 106061068, 304605202, 631920086, 857779016, 841431251, 805775211, 390359979, 923521, 961, 31,};
const int wi[24] = {1, 998244352, 86583718, 488723995, 369330050, 543653592, 382946991, 844956623, 91420391, 433414612, 288894979, 260490556, 857007890, 736054570, 474649464, 948509906, 114942468, 962405921, 667573957, 46809892, 304321983, 30429817, 293967900, 128805723,};

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

void ntt(ll *a, bool inverse = 0)
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

ll inv(ll x)
{
	ll ans = 1;
	ll y = mod-2;
	while (y) {
		if (y&1)
			ans = ans*x % mod;
		x = x*x % mod;
		y >>= 1;
	}
	return ans;
}

ll F[N], G[N], H[N];
ll fct[N];
int n;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	fct[0] = 1; Loop (i,1,N) fct[i] = fct[i-1]*i % mod;

	Loop (i,0,n) H[i] = inv(fct[i]); // foo(a) = 1/a!
	Loop (i,n/2+1,n)  F[i] = fct[n-i-1]*inv(i) % mod; // bar1(b) = (n-b-1)!/b
	Loop (i,0,n/2)  G[i] = fct[n-i-2]; // bar2(b) = (n-b-2)!

	// f[i] := foo(a)*bar1(b) (a+b = n-i)
	// g[i] := foo(a)*bar2(b) (a+b = n-i)
	ntt(F); ntt(G); ntt(H);
	Loop (i,0,N) F[i] = H[i]*F[i] % mod;
	Loop (i,0,N) G[i] = H[i]*G[i] % mod;
	ntt(F, 1); ntt(G, 1);
	Loop (i,0,n/2+1) swap(F[i], F[n-i]);
	Loop (i,0,n/2+1) swap(G[i], G[n-i]);

	Loop (i,2,n+1) F[i] = fct[n-i] % mod * F[i] % mod; // f[i] := (n-i)! - f[i]
	Loop (i,2,n+1) G[i] = (i-1)*fct[n-i] % mod * G[i] % mod; // g[i] := (i-1)(n-i)! - g[i]

	cout << (fct[n-1] + 2*mod - F[2] - G[2]) % mod << ' ';
	Loop (i,2,n+1)
		cout << (fct[n-1] + 2*mod - F[i] - G[i]) % mod << ' ' ;
	cout << '\n';
}