///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 998244353;
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

void ntt(vec& a, bool inverse = 0)
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
    int _N = N;
    int n = 31 - __builtin_clz(N);
    N = 2 << n;
    a.resize(N);
    b.resize(N);
    res.resize(N);
    ntt(a); ntt(b);
    Loop(i,0,N)
        res[i] = (a[i]*b[i]) % mod;
    ntt(res, 1);
    res.resize(_N-1);
}

ll mpow(ll x, ll y)
{
	ll ans=1;
	while(y){
		ans=y&1?ans*x%mod:ans;
		x = x*x%mod;
		y>>=1;
	}
	return ans;
}

void vpow(const vec& a, ll e, vec& res){
	res = a;
	if(e==1){return;}
	res.resize(2<<__lg(e));
	ntt(res);
	for(auto& x : res) x = mpow(x,e);
	ntt(res,1);
	res.resize(e+1);
}

const int N = 250'010;
int d[N];
int cnt[N];
ll fct[N];
int n;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	fct[0]=1;Loop(x,1,N)fct[x]=fct[x-1]*x%mod;
	Loop(i,1,n)
	{
		int v, u;
		cin >> v >> u;
		--v; --u;
		++d[v]; ++d[u];
		--d[i];
	}
	Loop(i,0,n) cnt[d[i]]++;
	vec ans = {1};
	LoopR(i,1,n){
		if(cnt[i]){
			vec v = {1, i};
			vpow(v, cnt[i], v);
			mul(ans, v, ans);
		}
	}
	ll fans = 0;
	Loop(i,0,ans.size()){
		fans += (i&1?-1:1)*ans[i]*fct[n-i]%mod;
	}
	fans = (fans%mod+mod)%mod;
	cout << fans << '\n';
}