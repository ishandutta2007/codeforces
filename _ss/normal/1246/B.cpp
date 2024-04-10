#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vt) vt.begin(),vt.end()
const ll maxn=1e5+10,mod=1e9+7,inf=1e12;
ll lp[maxn],n,k,a[maxn];

void sieve()
{
    for (int i=2;i<=1e5;i++)
        for (int j=i;j<=1e5;j+=i)
            if (!lp[j]) lp[j]=i;
}

ll tranf(ll x)
{
    ll res=1;
    while (x>1)
    {
        ll t=lp[x],d=0;
        while (lp[x]==t)
        {
            x/=t;
            d++;
        }
        d%=k;
        for (int i=1;i<=d;i++) res*=t;
    }
    return res;
}

ll findx(ll x)
{
    ll res=1;
    while (x>1)
    {
        ll t=lp[x];
        while (lp[x]==t) x/=t;
        for (int i=1;i<=k && res<=inf;i++) res*=t;
        if (res>inf) return -1;
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    cin>>n>>k;
    ll x;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=tranf(x);
    }
    sort(a+1,a+n+1);
    ll cnt=0;
    for (int i=1;i<=n;i++)
    {
        ll tmp=findx(a[i]);
        if (tmp==-1) continue;
        tmp/=a[i];
        ll vt1=lower_bound(a+1,a+n+1,tmp)-a;
        ll vt2=upper_bound(a+1,a+n+1,tmp)-a;
        cnt+=vt2-vt1;
        if (tmp==a[i]) cnt--;
    }
    cout<<cnt/2;
    return 0;
}