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
const ll maxn=1e5+10,mod=1e9+7,inf=2e9;
int n,b[maxn],bi[maxn],p[maxn],q[maxn],ans[maxn],premin[maxn];
pii a[maxn];

void update(int v,int x)
{
    for (int i=v;i<=n;i+=(i&-i)) bi[i]=min(bi[i],x);
}

int query(int v)
{
    int res=inf;
    for (int i=v;i;i-=(i&-i)) res=min(res,bi[i]);
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) a[i]=mp(b[i],i);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) bi[i]=n+1;
    int j=1;
    for (int i=1;i<=n;i++)
    {
        while (a[j].fi<((double)(a[i].fi)/(double)2))
        {
            update(n-a[j].se+1,a[j].se);
            j++;
        }
        p[a[i].se]=query(n-a[i].se+1);
    }
    for (int i=1;i<=n;i++) bi[i]=n+1;
    j=1;
    for (int i=1;i<=n;i++)
    {
        while (a[j].fi<((double)(a[i].fi)/(double)2))
        {
            update(a[j].se,a[j].se);
            j++;
        }
        q[a[i].se]=query(n);
    }
    premin[1]=p[1];
    p[n+1]=n+1;
    for (int i=2;i<=n+1;i++) premin[i]=min(premin[i-1],p[i]);
    int cc=inf;
    for (int i=1;i<=n;i++) cc=min(cc,q[i]);
    int mx=0,tmx,res=inf;
    for (int i=n;i;i--)
    {
        if (b[i]>mx)
        {
            mx=b[i];
            tmx=i;
        }
        res=min(res,p[i]);
        if (res==n+1)
        {
            int kk=min(q[tmx],premin[q[tmx]]);
            if (kk==n+1)
            {
                if (cc==n+1) ans[i]=-1;
                else ans[i]=n+1-i+n+cc-1;
            }
            else ans[i]=n-i+1+kk-1;
        }
        else ans[i]=res-i;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}