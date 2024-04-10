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

void _dbg(){}
template<class T, class... U> void _dbg(T x, U... y){
	cout << x << ' ';
	_dbg(y...);
}
template<class... T> void dbg(T... x){
	#ifdef DBG
	cout << "dbg: ";
	_dbg(x...);
	cout << '\n';
	#endif
}
template<class... T> void vdbg(T... x){
	#ifdef VRB
	cout << "vdbg: ";
	_dbg(x...);
	cout << '\n';
	#endif
}

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
    int n = 31 - __builtin_clz(N);
    int dN = N;
    N = 2 << n;
    a.resize(N);
    b.resize(N);
    res.resize(N);
    ntt(a); ntt(b);
    Loop(i,0,N)
        res[i] = (a[i]*b[i]) % mod;
    ntt(res, 1);
    res.resize(dN-1);
}

const int N = 100'010;
map<string,vec> mp =
{
	{"??", {1, 2, 1}},
	{"?W", {0, 1, 1}},
	{"?B", {1, 1}},
	{"W?", {0, 1, 1}},
	{"WW", {0, 0, 1}},
	{"WB", {0, 1}},
	{"B?", {1, 1}},
	{"BW", {0, 1}},
	{"BB", {1}},
};
string a[N];
int n;

ll mpow(ll x, ll y)
{
	ll ans = 1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
void mpow(vec& x, ll y)
{
	int N = (x.size()-1)*y+1;
    int n = 31 - __builtin_clz(N);
    int fN = 2 << n;
    x.resize(fN);
    ntt(x);
    Loop(i,0,fN)
        x[i] = mpow(x[i],y);
    ntt(x, 1);
    x.resize(N);
}

vec solve(){
	map<string, int> cnt;
	Loop(i,0,n) cnt[a[i]]++;
	vec ans = {1};
	vec tmp;
	for(auto [s, x] : cnt){
		tmp = mp[s];
		mpow(tmp,x);
		mul(ans,tmp,ans);
	}
	return ans;
}

map<string,int> mpwb={
	{"??", 1},
	{"?B", 1},
	{"W?", 1},
	{"WB", 1},
};
map<string,int> mpbw={
	{"??", 1},
	{"?W", 1},
	{"B?", 1},
	{"BW", 1},
};
map<string,int> mpwbbw={
	{"??", 2},
	{"?B", 1},
	{"W?", 1},
	{"WB", 1},
	{"?W", 1},
	{"B?", 1},
	{"BW", 1},
};

ll cnt(map<string,int>& mp){
	ll ans=1;
	Loop(i,0,n)
		ans = (ans*mp[a[i]]%mod);
	return ans;
}


string dard[] = {"??","?W","?B","W?","WB","WW","B?","BW","BB"};

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> a[i];
	auto tmp = solve();
	tmp.resize(n+10);
	//cout << tmp.size() << '\n';
	ll ans = tmp[n];
	ans -= cnt(mpwbbw);
	ans += cnt(mpwb);
	ans += cnt(mpbw);
	ans = (ans%mod+mod)%mod;
	cout << ans << '\n';
	//cout << clock() << '\n';
}