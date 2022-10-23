#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+5;
ll n,a[maxn],q,maxx=-1e9,maxvt,maxx_ans;
vector<ll> b;
pii ans[maxn];
int main()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>maxx)
        {
            maxx=a[i];
            maxvt=i;
        }
    }
    for (int i=maxvt+1;i<=n;i++) b.pb(a[i]);
    maxx_ans=maxx;
    maxx=a[1];
    for (int i=2;i<=maxvt;i++)
    {
        ans[i-1]={maxx,a[i]};
        if (maxx>a[i]) b.pb(a[i]);
        else
        {
            b.pb(maxx);
            maxx=a[i];
        }
    }
    ll x;
    for (int i=1;i<=q;i++)
    {
        cin>>x;
        if (x<maxvt) cout<<ans[x].fi<<" "<<ans[x].se<<endl;
        else cout<<maxx_ans<<" "<<b[(x-maxvt)%b.size()]<<endl;
    }
    return 0;
}