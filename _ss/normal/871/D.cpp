#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e7+1,msiz=2,mod=1e9+7,inf=1e18;
ll dp[maxn],lp[maxn],sl[maxn];
vector<pii> vt;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    for (int i=n;i>n/2;i--) dp[i]=1;
    for (int i=n/2;i;i--)
    {
        dp[i]=(n/i)*(n/i);
        for (int j=i*2;j<=n;j+=i) dp[i]-=dp[j];
    }
    ll sl1=n*(n-1)-dp[1]+1,sl3=0;
    for (int i=2;i*i<=n;i++)
        if (!lp[i])
        for (int j=i*2;j<=n;j+=i)
            if (!lp[j]) lp[j]=i;
    for (int i=2;i<=n;i++)
        if (!lp[i]) lp[i]=i;
    for (int i=n/2+1;i<=n;i++)
        if (lp[i]==i) sl3++;
    for (int i=2;i<=n;i++) sl[lp[i]]++;
    for (int i=2;i<=n;i++)
        if (sl[i]) vt.pb(make_pair(i,sl[i]));
    ll sl2=0;
    for (int i=0;i<(int)(vt.size());i++)
        for (int j=0;j<(int)(vt.size());j++)
            if (vt[i].fi*vt[j].fi>n) break;
            else
            {
                if (i==j) sl2+=vt[i].se*(vt[j].se-1);
                else sl2+=vt[i].se*vt[j].se;
            }
    //cout<<dp[1]<<endl;
    //for (int i=1;i<=n;i++) cout<<dp[i]<<endl;
    sl3=sl3*(n-sl3-1)*2+sl3*(sl3-1);
    //cout<<sl1<<" "<<sl2<<" "<<sl3<<endl;
    cout<<(sl1+(sl2-sl1)*2+(((n-2)*(n-1))-sl3-sl2)*3)/2;
    return 0;
}