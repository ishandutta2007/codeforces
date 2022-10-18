#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

const ll MOD=998244353;

ll pw(ll a,ll n)
{
    ll rt=1;
    for(;n;n>>=1,a=a*a%MOD)
        if(n&1) 
            rt=rt*a%MOD;
    return rt;
}

ll arr[300005],sum[300005],ans[300005];

int main()
{
    IOS();
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
        cin >> arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;++i)
        sum[i]=(arr[i]+sum[i-1])%MOD;
    for(int i=1;i<=n/2;++i)
        ans[n-i]=(arr[i]+ans[n-i+1])%MOD;
    for(int i=n/2+1,nw=2;i<n;++i)
    {
        int sp=n-i;
        while((ll)nw*sp<(ll)i)
            ++nw;
        int r=i-(nw-1)*sp;
        ans[n-i]=sum[r]*(nw);
        for(int k=r,j=nw-1;j>0;--j,k+=sp)
            ans[n-i]=(ans[n-i]+(sum[k+sp]-sum[k]+MOD)%MOD*j%MOD)%MOD;
    }
    for(int i=1;i<=n;++i)
        cout << ans[i]*pw(n,MOD-2)%MOD << " \n"[i==n]; 
}