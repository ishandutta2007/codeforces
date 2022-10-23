#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e6+10,mod=1e9+7,inf=1e9,max_v=1e7;
vector<int> a[max_v+10];
pii res[max_v+10];
ll b[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[x].pb(i);
        b[i]=x;
    }
    for (int i=1;i<=max_v;i++)
    {
        res[i]=mp(inf,inf);
        for (int j=i;j<=max_v;j+=i)
        {
            for (int t=0;t<a[j].size();t++)
            if (res[i].fi==inf) res[i].fi=a[j][t];
            else
            {
                res[i].se=a[j][t];
                break;
            }
            if (res[i].se!=inf) break;
        }
    }
    pii ans=res[1];
    ll kq=b[ans.fi]*b[ans.se];
    for (int i=1;i<=max_v;i++)
        if (res[i].fi!=inf && res[i].se!=inf)
        {
            if (b[res[i].fi]*b[res[i].se]/i<kq)
            {
                kq=b[res[i].fi]*b[res[i].se]/i;
                ans=res[i];
            }
        }
    if (ans.fi>ans.se) swap(ans.fi,ans.se);
    cout<<ans.fi<<" "<<ans.se;
    return 0;
}