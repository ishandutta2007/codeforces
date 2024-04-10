#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
ll s[maxn],n,m,q,t=0;
vector<ll> vt;

void ans()
{
    ll tmp=lower_bound(vt.begin(),vt.end(),t)-vt.begin();
    if (tmp==vt.size()) printf("%I64d\n",t-vt.back());
    else if (tmp==0) printf("%I64d\n",vt[tmp]-t);
    else printf("%I64d\n",min(t-vt[tmp-1],vt[tmp]-t));
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ll x;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d",&x);
        if (i&1) t+=x; else t-=x;
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%I64d",&x);
        s[i]=s[i-1];
        if (i&1) s[i]-=x; else s[i]+=x;
    }
    for (int i=1;i<=m-n+1;i++)
        if (i&1) vt.pb(s[i-1]-s[i+n-1]);
        else vt.pb(s[i+n-1]-s[i-1]);
    sort(vt.begin(),vt.end());
    int l,r;
    ans();
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d %I64d",&l,&r,&x);
        if ((r-l+1)&1)
        {
            if (l&1) t+=x;
            else t-=x;
        }
        ans();
    }
    return 0;
}