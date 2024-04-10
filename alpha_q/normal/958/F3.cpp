#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<long long int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef unsigned long long int ULL;
 
#define PB push_back
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
LL power(LL a, LL p, LL mod)
{
    LL ret = 1;
    while(p)
    {
        if(p&1)ret = (ret*a)%mod;
        a=(a*a)%mod;
        p/=2;
    }
    return ret;
}
const int MOD = 1009;
 
//use mul(vi a,vi b) to multiply two polynomials a and b
//the higher power coefficients have the lower index in the vectors
//a= [ a(n-1) , a(n-2) , a(n-3) , ............a(0) ]
//the mul function will return a vector of long long
//If mod is different just change the above predefined mod
 
namespace FFT
{
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long double ld;
const ld PI = acos(-1);
struct base
{
    typedef double T;
    T re, im;
    base() :re(0), im(0) {}
    base(T re) :re(re), im(0) {}
    base(T re, T im) :re(re), im(im) {}
    base operator + (const base& o) const
    {
        return base(re + o.re, im + o.im);
    }
    base operator - (const base& o) const
    {
        return base(re - o.re, im - o.im);
    }
    base operator * (const base& o) const
    {
        return base(re * o.re - im * o.im, re * o.im + im * o.re);
    }
    base operator * (ld k) const
    {
        return base(re * k, im * k) ;
    }
    base conj() const
    {
        return base(re, -im);
    }
};
const int N = 21;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];
void build_rev(int k)
{
    static int rk = -1;
    if( k == rk )return ;
    rk = k;
    fore(i, 1, (1<<k) )
    {
        int j = rev[i-1], t = k-1;
        while( t >= 0 && ((j>>t)&1) )
        {
            j ^= 1 << t;
            --t;
        }
        if( t >= 0 )
        {
            j ^= 1 << t;
            --t;
        }
        rev[i] = j;
    }
}
void fft(base *a, int k)
{
    build_rev(k);
    int n = 1 << k;
    forn(i, n) if( rev[i] > i ) swap(a[i], a[rev[i]]);
    for(int l = 2, ll = 1; l <= n; l += l, ll += ll)
    {
        if( w[ll].re == 0 && w[ll].im == 0 )
        {
            ld angle = PI / ll;
            base ww( cosl(angle), sinl(angle) );
            if( ll > 1 ) for(int j = 0; j < ll; ++j)
                {
                    if( j & 1 ) w[ll + j] = w[(ll+j)/2] * ww;
                    else w[ll + j] = w[(ll+j)/2];
                }
            else w[ll] = base(1, 0);
        }
        for(int i = 0; i < n; i += l) forn(j, ll)
        {
            base v = a[i + j], u = a[i + j + ll] * w[ll + j];
            a[i + j] = v + u;
            a[i + j + ll] = v - u;
        }
    }
}
VI mul(const VI& a, const VI& b)
{
    int k = 1;
    while( (1<<k) < (SZ(a) + SZ(b)) ) ++k;
    int n = (1<<k);
    forn(i, n) f1[i] = base(0,0);
    forn(i, a.size()) f1[i] = f1[i] + base(a[i], 0);
    forn(i, b.size()) f1[i] = f1[i] + base(0, b[i]);
    fft(f1, k);
    forn(i, 1 + n/2)
    {
        base p = f1[i] + f1[(n-i)%n].conj();
        base _q = f1[(n-i)%n] - f1[i].conj();
        base q(_q.im, _q.re);
        f1[i] = (p * q) * 0.25;
        if( i > 0 ) f1[(n - i)] = f1[i].conj();
    }
    forn(i, n) f1[i] = f1[i].conj();
    fft(f1, k);
    VI r(SZ(a) + SZ(b));
    forn(i, SZ(r) )
    {
        r[i] = LL (f1[i].re / n + 0.5) % MOD;
    }
    return r;
}
}
int c[200011];
VI multiply(int l,int r)
{
    if(l==r)
    {
        VI a1;
        for(int i=0;i<=c[l];i++)
            a1.pb(1LL);
        return a1;
    }
    VI a1,b;
    int mid=(l+r)/2;
    a1=multiply(l,mid);
    b=multiply(mid+1,r);
    return FFT::mul(a1,b);
}
int main()
{
    int n,i,j,k,m;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        c[a]++;
    }
    VI ans=multiply(1,200000);
    printf("%lld\n",ans[k]);
    return 0;
}