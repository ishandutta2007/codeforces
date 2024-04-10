#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

//***************FFT optimized code************//
typedef complex<double> base;

void fft(vector<base> &a,bool invert)
{
    int n=(int)a.size();
    for(int i=1,j=0;i<n ;++i)
    {
        int bit=n>>1;
        for(;j>=bit;bit>>=1)
            j-=bit;
        j+=bit;
        if(i<j)
            swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len<<=1)
    {
        double angle=2*PI/len*(invert?-1:1);
        // w_len is omega for this len
        base w_len(cos(angle),sin(angle)),w(1);
        // yaha se apna root to aa gaya 
        base pow[len/2];
        // bas uski aadhi powers ye rahi aur bachi aadhi inki negative hongi
        // imagine at argand plane for nth roots of unity
        pow[0]=w;
        for(int i=1;i<len/2;++i)
            pow[i]=pow[i-1]*w_len;
        for(int i=0;i<n;i+=len)
        {
            for(int j=0;j<len/2;++j)
            {
                base u=a[i+j],v=a[i+j+len/2]*pow[j];
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
            }
        }
    }
    if(invert)
        for(int i=0;i<n;++i)
            a[i]/=n;
}
void multiply(vector<ll> &a,vector<ll> &b,vector<ll> &res)
{
    int x=max((int)a.size(),(int)b.size());
    int n=1;
    vector<base> fa(all(a)),fb(all(b));
    while(n<x)n<<=1;
    n<<=1;
    fa.resize(n);fb.resize(n);
    fft(fa,false);fft(fb,false);
    for(int i=0;i<n;++i)
        fa[i]*=fb[i];
    fft(fa,true);
    res.resize(n);
    for(int i=0;i<n;++i)
    {
        res[i]=(ll)(fa[i].real()+0.5);
        res[i]=res[i]>0;
    }
}

int _runtimeTerror_()
{
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> a(x+1,0);
    for(int i=0;i<=n;++i)
    {
        int l;cin>>l;
        a[l]=1;
    }
    vector<ll> b=a,c;
    reverse(all(b));
    multiply(a,b,c);
    //cout<<c[x+10]<<"\n";
    vector<ll> ans(1000001,-1);
    for(int i=1;i<=1000000;++i)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            if(i<=2*y)
                continue;
            ll xy=i-2*y;
            if(xy&1)continue;
            xy/=2;
            if(xy+x<=2*x && c[xy+x]==1)
                amax(ans[j],i);
        }
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x;
        cin>>x;
        cout<<ans[x]<<" ";
    }
    //cout<<ans[30]<<"\n";
    //cout<<ans[200]<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}