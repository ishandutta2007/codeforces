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

const ll INF=1e9;
ll arr[100005],dp[100005],mxdp[100005];

int main()
{
    IOS();
    ll t,n,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(int i=1;i<=n;++i)
            cin >> arr[i];
        sort(arr+1,arr+n+1);
        dp[n+1]=0,mxdp[n+1]=0;
        for(int i=n;i>=1;--i)
        {
            ll d=(x-1)/arr[i]+1;
            if(i+d>n+1)
                dp[i]=-INF;
            else
                dp[i]=mxdp[i+d]+1;
            mxdp[i]=max(dp[i],mxdp[i+1]);
        }
        cout << mxdp[1] << "\n";
    }
}