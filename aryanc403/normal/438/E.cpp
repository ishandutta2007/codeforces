// Setter Implementation.

/*  
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 998244353L;
// const lli maxN = 1000000007L;

typedef long long s64;

const int Mod = 998244353;
const int Mod_G = 3;

const int MaxCN = 100000;
const int MaxS = 100000;

struct modint
{
	int a;

	modint(){a=0;}
	modint(int _a)
	{
		a = _a % Mod;
		if (a < 0)
			a += Mod;
	}
	modint(s64 _a)
	{
		a = _a % Mod;
		if (a < 0)
			a += Mod;
	}

	inline modint operator-() const
	{
		return -a;
	}
	inline modint inv() const
	{
		int x1 = 1, x2 = 0, x3 = Mod;
		int y1 = 0, y2 = 1, y3 = a;
		while (y3 != 1)
		{
			int k = x3 / y3;
			x1 -= y1 * k, x2 -= y2 * k, x3 -= y3 * k;
			swap(x1, y1), swap(x2, y2), swap(x3, y3);
		}
		return y2 >= 0 ? y2 : y2 + Mod;
	}

	friend inline modint operator+(const modint &lhs, const modint &rhs)
	{
		return lhs.a + rhs.a;
	}
	friend inline modint operator-(const modint &lhs, const modint &rhs)
	{
		return lhs.a - rhs.a;
	}
	friend inline modint operator*(const modint &lhs, const modint &rhs)
	{
		return (s64)lhs.a * rhs.a;
	}
	friend inline modint operator/(const modint &lhs, const modint &rhs)
	{
		return lhs * rhs.inv();
	}

	inline modint div2() const
	{
		return (s64)a * ((Mod + 1) / 2);
	}
};

ostream& operator << (ostream& out, const modint &a) {
	return out<<a.a<<" ";
}

inline modint modpow(const modint &a, const int &n)
{
	modint res = 1;
	modint t = a;
	for (int i = n; i > 0; i >>= 1)
	{
		if (i & 1)
			res = res * t;
		t = t * t;
	}
	return res;
}

const int MaxN = 131072;
const int MaxTN = MaxN * 2;

modint prePowG[MaxTN];

void fft(int n, modint *a, int step, modint *out)
{
	if (n == 1)
	{
		out[0] = a[0];
		return;
	}
	int m = n / 2;
	fft(m, a, step + 1, out);
	fft(m, a + (1 << step), step + 1, out + m);
	for (int i = 0; i < m; i++)
	{
		modint e = out[i], o = out[i + m] * prePowG[i << step];
		out[i] = e + o;
		out[i + m] = e - o;
	}
}

void poly_mulTo(int n, modint *f, modint *g)
{
	/*static modint c[MaxN];
	for (int i = 0; i < n; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; i + j < n; j++)
			c[i + j] = c[i + j] + f[i] * g[j];
	copy(c, c + n, f);
	return;*/

	int tn = n * 2;
	static modint tf[MaxTN], tg[MaxTN];
	copy(f, f + n, tf), fill(tf + n, tf + tn, modint(0));
	copy(g, g + n, tg), fill(tg + n, tg + tn, modint(0));

	modint rg = modpow(Mod_G, (Mod - 1) / tn);
	prePowG[0] = 1;
	for (int i = 1; i < tn; i++)
		prePowG[i] = prePowG[i - 1] * rg;

	static modint dftF[MaxTN], dftG[MaxTN];
	fft(tn, tf, 0, dftF);
	fft(tn, tg, 0, dftG);

	for (int i = 0; i < tn; i++)
		dftF[i] = dftF[i] * dftG[i];

	reverse(prePowG + 1, prePowG + tn);
	fft(tn, dftF, 0, tf);
	reverse(prePowG + 1, prePowG + tn);

	modint revTN = modint(tn).inv();
	for (int i = 0; i < n; i++)
		f[i] = tf[i] * revTN;
}

void poly_inv(int n, modint *f, modint *r)
{
	// assert(f[0] == 1)
	fill(r, r + n, modint(0));
	// r[0] = 1;
    r[0] = f[0].inv();

	for (int m = 2; m <= n; m <<= 1)
	{
		int h = m / 2;
		static modint nr[MaxN];
		copy(f, f + m, nr);
		poly_mulTo(m, nr, r);
		fill(nr, nr + h, modint(0));
		for (int i = h; i < m; i++)
			nr[i] = -nr[i];
		poly_mulTo(m, nr, r);
		copy(nr + h, nr + m, r + h);
	}
}

void poly_sqrt(int n, modint *f, modint *s)
{
	assert(f[0].a == 1);
	fill(s, s + n, modint(0));
	s[0] = 1;

	static modint rs[MaxN];
	fill(rs, rs + n, modint(0));
	rs[0] = 1;
	for (int m = 2; m <= n; m <<= 1)
	{
		int h = m / 2;
		static modint nrs[MaxN];
		copy(s, s + h, nrs), fill(nrs + h, nrs + m, modint(0));
		poly_mulTo(m, nrs, rs);
		fill(nrs, nrs + h, modint(0));
		for (int i = h; i < m; i++)
			nrs[i] = -nrs[i];
		poly_mulTo(m, nrs, rs);
		copy(rs, rs + h, nrs);
		poly_mulTo(m, nrs, f);
		for (int i = h; i < m; i++)
			s[i] = nrs[i].div2();
		copy(s, s + m, nrs);
		poly_mulTo(m, nrs, rs);
		fill(nrs, nrs + h, modint(0));
		for (int i = h; i < m; i++)
			nrs[i] = -nrs[i];
		poly_mulTo(m, nrs, rs);
		copy(nrs + h, nrs + m, rs + h);
	}
}

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void checkInverse(lli n,vector<modint> a)
{
    // vector<modint> a;
    vector<modint> b;
    // a.clear();a.reserve(n);
    // fo(i,n)
        // a.pb(rnd(1,10));

    b.resize(n);

    poly_inv(n,&a[0],&b[0]);
    // dbg(a,b);

    poly_mulTo(n,&a[0],&b[0]);
    dbg("Inverse Check",a);
}

void checkSqrt(lli n,vector<modint> a)
{
    // vector<modint> a;
    vector<modint> b;

    // a.clear();a.reserve(n);
    // fo(i,n)
    //     a.pb(rnd(1,10));
    // a[0]=1;
    b.resize(n);

    poly_sqrt(n,&a[0],&b[0]);
    // dbg(a,b);

    poly_mulTo(n,&b[0],&b[0]);
    // dbg(a,b);
    lli i;
    fo(i,n)
        a[i]=a[i]-b[i];
    dbg("Sqrt check",a);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    // cin>>n;
    // checkInverse(n);
    // checkSqrt(n);

    lli n,m;
    const lli M = 1LL<<17;
    vector<modint> a(M),b(M);
    // dbg(a);

    cin>>n>>m;
    dbg(n,m);

    while(n--)
    {
        cin>>in;
        if(in>m)
            continue;
        a[in]=modint(1);
    }

    //-4*c+1
    for(auto &x:a)
        x=-4*x;
    a[0]=a[0]+1;

    //sqrt(1-4*c)
    // algebra::sqrt(a,a,M);
    // dbg(a);
    poly_sqrt(M,&a[0],&b[0]);
    // checkSqrt(M,a);
    a=b;

    //1+sqrt(1-4*c)
    a[0]=a[0]+1;

    // algebra::inverse(a,a,m);
    poly_inv(M,&a[0],&b[0]);
    // checkInverse(M,a);
    a=b;

    for(auto &x:a)
        x=2*x;

    // dbg(a);
    dbg(m);
    repA(i,1,m)
        cout<<a[i]<<endl;

}   aryanc403();
    return 0;
}