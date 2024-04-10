#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e6+10,mod=1e9+7,inf=1e18;
int p[N],n;
ll a[N],sl[N],dp[N];
vector<ll> divisor;

ll gcd(ll t1,ll t2)
{
    while (t2)
    {
        ll r=t1%t2;
        t1=t2;
        t2=r;
    }
    return t1;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for (int i=2;i<=n;i++) scanf("%d",&p[i]);
    for (int i=n;i>1;i--) a[p[i]]+=a[i];
    for (ll i=1;i*i<=a[1];i++)
        if (a[1]%i==0)
        {
            divisor.pb(i);
            if (a[1]/i!=i) divisor.pb(a[1]/i);
        }
    sort(all(divisor));
    for (int i=1;i<=n;i++)
    {
        ll val=gcd(a[i],a[1]);
        int vt=lower_bound(all(divisor),val)-divisor.begin();
        sl[vt]++;
    }
    for (int i=0;i<(int)divisor.size();i++)
        for (int j=i-1;j>=0;j--)
            if (divisor[i]%divisor[j]==0) sl[j]+=sl[i];
    dp[divisor.size()-1]=1;
    for (int i=divisor.size()-1;i>=0;i--)
        for (int j=i-1;j>=0;j--)
            if (divisor[i]%divisor[j]==0 && sl[i]==a[1]/divisor[i] && sl[j]==a[1]/divisor[j]) dp[j]=(dp[j]+dp[i])%mod;
    ll res=0;
    for (int i=0;i<(int)divisor.size();i++) res=(res+dp[i])%mod;
    cout<<res;
    return 0;
}