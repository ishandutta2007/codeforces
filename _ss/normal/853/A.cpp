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
const ll maxn=3e5+10,mod=1e9+7,inf=1e18;
int k,n,ans[maxn];
ll c[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>c[i];
    ll res=0,s=0;
    priority_queue<pii> q;
    for (int i=1;i<=k;i++)
    {
        res+=s;
        s+=c[i];
        q.push(mp(c[i],i));
    }
    for (int i=k+1;i<=n;i++)
    {
        res+=s;
        s+=c[i];
        q.push(mp(c[i],i));
        s-=q.top().fi;
        ans[q.top().se]=i;
        q.pop();
    }
    for (int i=n+1;i<=n+k;i++)
    {
        res+=s;
        s-=q.top().fi;
        ans[q.top().se]=i;
        q.pop();
    }
    cout<<res<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}