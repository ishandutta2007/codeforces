#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 2005;

int lsum[N],rsum[N],rd[N],sum[N];
int l[N],r[N];

int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
        cin>>l[i]>>r[i];
    auto in = [&](int lx,int i)
    {
        int rx = lx + k-1;
        if(l[i]>rx || r[i]<lx)
            return 0;
        amax(lx,l[i]);
        amin(rx,r[i]);
        return rx-lx+1;
    };
    int ans = 0;
    for(int i=1;i<=n-k+1;++i)
    {
        int val = 0;
        for(int j=1;j<=n;++j)
            lsum[j] = rsum[j] = rd[j] = sum[j] = 0;
        for(int j=1;j<=m;++j)
        {
            int u = in(i,j);
            val += u;
            if(u == r[j]-l[j]+1)
                continue;
            rsum[r[j]-u] += 1;
            rd[r[j]-u] += 1;
            int uu = r[j]-k;
            amax(uu,l[j]-1);
            rsum[uu] -= r[j]-u-uu+1;
            rd[uu] -= 1;
            if(uu>=l[j])
                sum[l[j]] += r[j]-u-uu,sum[uu+1] -= r[j]-u-uu;
            if(r[j]-k+1<=0)
                continue;
            int lj = l[j];
            if(r[j]-k+1<l[j])
            {
                lj = r[j]-k+1;
                sum[lj] += r[j]-l[j]+1-u,sum[l[j]] -= r[j]-l[j]+1-u;
            }
            int vx = l[j] + u - k;
            rsum[lj-1] += lj - vx-1;
            int t = lj-vx-1;
            rd[lj-1] -= 1;
            amax(vx,0);
            rd[vx] += 1;
            rsum[vx] -= t - (lj-vx-1);
        }
        for(int j=n;j>=1;--j)
        {
            lsum[j] = lsum[j+1];
            lsum[j] += rsum[j] + rd[j+1];
            rd[j] += rd[j+1];
        }
        for(int j=1;j<=n;++j)
        {
            sum[j] += sum[j-1];
            lsum[j] += sum[j];
        }

        int mx = 0;
        for(int j=1;j<=n-k+1;++j)
            amax(mx,lsum[j]);
        val += mx;
        amax(ans,val);
    }
    cout<<ans<<"\n";
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

// Ek dum chutiya implementation aur bilkul ghatiya ques bcc