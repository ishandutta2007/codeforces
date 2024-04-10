#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=2e18;
ll a[32],n,l;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    ll x;
    for (int i=1;i<=31;i++) a[i]=inf;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        for (int j=i;j<=31;j++)
        {
            a[j]=min(a[j],x);
            x+=x;
        }
    }
    for (int i=30;i;i--) a[i]=min(a[i],a[i+1]);
    ll res=0,ans=inf;
    for (int i=31;i;i--)
        if (l&(1<<(i-1))) res+=a[i];
        else ans=min(ans,res+a[i]);
    cout<<min(ans,res);
    return 0;
}