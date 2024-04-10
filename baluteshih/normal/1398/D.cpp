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

int arr[3][205];
ll dp[205][205][205];

void mx(ll &tar,ll v)
{
    tar=max(tar,v);
}

int main()
{
    IOS();
    int n[3];
    ll ans=0;
    cin >> n[0] >> n[1] >> n[2];
    for(int i=0;i<3;++i)
        for(int j=1;j<=n[i];++j)
            cin >> arr[i][j];
    sort(arr[0]+1,arr[0]+n[0]+1,greater<int>());
    sort(arr[1]+1,arr[1]+n[1]+1,greater<int>());
    sort(arr[2]+1,arr[2]+n[2]+1,greater<int>());
    for(int emt=0,nw=1,nxt=2,ct=0;ct<3;nw=nxt,nxt=emt,++emt,++ct)
    {
        for(int i=0;i<=n[emt];++i)
            for(int j=0;j<=n[nw];++j)
                for(int k=0;k<=n[nxt];++k)
                {
                    if(i==0&&j==0&&k==0) continue;
                    dp[i][j][k]=0;
                    if(i)
                        mx(dp[i][j][k],dp[i-1][j][k]);
                    if(j)
                        mx(dp[i][j][k],dp[i][j-1][k]);
                    if(k)
                        mx(dp[i][j][k],dp[i][j][k-1]);
                    if(j&&k)
                        mx(dp[i][j][k],dp[i][j-1][k-1]+arr[nw][j]*arr[nxt][k]);
                    if(i&&j)
                        mx(dp[i][j][k],dp[i-1][j-1][k]+arr[emt][i]*arr[nw][j]);
                    if(i&&k)
                        mx(dp[i][j][k],dp[i-1][j][k-1]+arr[emt][i]*arr[nxt][k]);
                }
        ans=max(ans,dp[n[emt]][n[nw]][n[nxt]]);
    }
    cout << ans << "\n";
}