//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
namespace FFT {
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
	typedef long double ld;
	const double PI = acos(-1);
	struct base {
		typedef double T; T re, im;
		base() :re(0), im(0) {}
		base(T re) :re(re), im(0) {}
		base(T re, T im) :re(re), im(im) {}
		base operator + (const base& o) const { return base(re + o.re, im + o.im); }
		base operator - (const base& o) const { return base(re - o.re, im - o.im); }
		base operator * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
		base operator * (ld k) const { return base(re * k, im * k) ;}
		base conj() const { return base(re, -im); }
	};
	const int N = 22;
	const int MAXN = (1<<N);
	base w[MAXN];
	base f1[MAXN];
	int rev[MAXN];
	void build_rev(int k) {
		static int rk = -1;
		if( k == rk )return ; rk = k;
		fore(i, 1, (1<<k) ) {
			int j = rev[i-1], t = k-1;
			while( t >= 0 && ((j>>t)&1) ) { j ^= 1 << t; --t; }
			if( t >= 0 ) { j ^= 1 << t; --t; }
			rev[i] = j;
		}
	}
	void fft(base *a, int k) {
		build_rev(k); int n = 1 << k;
		forn(i, n) if( rev[i] > i ) swap(a[i], a[rev[i]]);
		for(int l = 2, ll = 1; l <= n; l += l, ll += ll) {
			if( w[ll].re == 0 && w[ll].im == 0 ) {
				ld angle = PI / ll;
				base ww( cosl(angle), sinl(angle) );
				if( ll > 1 ) for(int j = 0; j < ll; ++j) {
					if( j & 1 ) w[ll + j] = w[(ll+j)/2] * ww;
					else w[ll + j] = w[(ll+j)/2];
				} else w[ll] = base(1, 0);
			}
			for(int i = 0; i < n; i += l) forn(j, ll) {
				base v = a[i + j], u = a[i + j + ll] * w[ll + j];
				a[i + j] = v + u; a[i + j + ll] = v - u;
			}
		}
	}
	VI mul(const VI& a, const VI& b) {
		int k = 1;
		while( (1<<k) < (SZ(a) + SZ(b)) ) ++k;
		int n = (1<<k);
		forn(i, n) f1[i] = base(0,0);
		forn(i, a.size()) f1[i] = f1[i] + base(a[i], 0);
		forn(i, b.size()) f1[i] = f1[i] + base(0, b[i]);
		fft(f1, k);
		forn(i, 1 + n/2) {
			base p = f1[i] + f1[(n-i)%n].conj();
			base _q = f1[(n-i)%n] - f1[i].conj();
			base q(_q.im, _q.re);
			f1[i] = (p * q) * 0.25;
			if( i > 0 ) f1[(n - i)] = f1[i].conj();
		}
		forn(i, n) f1[i] = f1[i].conj();
		fft(f1, k);
		VI r(SZ(a) + SZ(b));
		forn(i, SZ(r) ) {
			r[i] = LL (f1[i].re / n + 0.5);
		}
		/*Uncomment for multiplication of two numbers
		  int carry = 0;
		  for (int i=0; i<SZ(r); ++i) {
		  r[i] += carry;
		  carry = r[i] / 10;
		  r[i] %= 10;
		  }
		  */
		return r;
	}
} // end of FFT namespace
const int N = int(2e5)+10;
int k;
string T,P,S;
int n,m;
int match[4][N];
int cnt[4];
int d[2][N];
VI PP,TP;
void get(int j)
{
	for(int i=0;i<n;i++)
		if(S[j]==T[i])TP[i]=1;
		else TP[i]=0;
	d[0][0]=(TP[0]?0:int(1e9));
	for(int i=1;i<n;i++)
		if(TP[i])d[0][i]=0;
		else d[0][i]=d[0][i-1]+1;
	d[1][n-1]=(TP[n-1]?0:int(1e9));
	for(int i=n-2;i>=0;i--)
		if(TP[i])d[1][i]=0;
		else d[1][i]=d[1][i+1]+1;
	for(int i=0;i<n;i++)
		if(k>=min(d[0][i],d[1][i])) TP[i]=1;
		else TP[i]=0;
	for(int i=0;i<m;i++)
		if(P[i]==S[j])PP[i]=1;
		else PP[i]=0;
	VI prod = FFT::mul(TP,PP);
	for(int i=0;i<n;i++)
		match[j][i]=prod[i+m-1];
}
int main()
{
	S="ATGC";
	fast_io;
	cin>>n>>m>>k>>T>>P;
	reverse(ALL(P));
	TP.resize(n);PP.resize(m);
	for(int i=0;i<SZ(P);i++)
		for(int j=0;j<SZ(S);j++)
			if(P[i]==S[j])
				cnt[j]++;
	for(int i=0;i<SZ(S);i++)get(i);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		bool ok=true;
		for(int j=0;j<4;j++)
			if(match[j][i]!=cnt[j])
				ok=false;
		if(ok)ans++;
	}
	dout(ans);
	return 0;
}