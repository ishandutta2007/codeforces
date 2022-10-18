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

ll a[100005],ans[100005];
pll srt[1000005];

ll get_val(ll x,ll bd)
{
    ll l=0,r=x;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(x-3*mid*mid-3*mid-1>=bd)
            l=mid+1;
        else
            r=mid;
    }
    return l;
}

int main()
{
    IOS();
    ll n,k,tp=0,sum=0;
    cin >> n >> k;
    for(int i=1;i<=n;++i)
        cin >> a[i];
    ll l=-4e18,r=1e18;
    while(r-l>1)
    {
        ll mid=(l+r)/2,cnt=0;
        for(int i=1;i<=n;++i)
            cnt+=get_val(a[i],mid);
        if(cnt<=k)
            r=mid;
        else 
            l=mid;
    }
    for(int i=1;i<=n;++i)
    {
        ans[i]=get_val(a[i],r),sum+=ans[i];
        for(int j=0;j<3&&ans[i]+j<a[i];++j)
            srt[tp++]=pll(a[i]-3*(ans[i]+j)*(ans[i]+j)-3*(ans[i]+j)-1,i);
    }
    sort(srt,srt+tp,greater<pll>());
    for(int i=0;i<k-sum;++i)
        ++ans[srt[i].Y];
    for(int i=1;i<=n;++i)
        cout << ans[i] << " \n"[i==n];
}