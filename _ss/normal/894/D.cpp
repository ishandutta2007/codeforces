#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e6+1;
ll n,m,a[maxn];
vector<ll> kc[maxn*2],cd[maxn*2];

void read()
{
    cin>>n>>m;
    for (int i=1;i<n;i++) scanf("%I64d",&a[i]);
}


void megh(int st)
{
    int t1=0,t2=0;
    while (t1<kc[st*2].size() || t2<kc[st*2+1].size())
    {
        if (t2==kc[st*2+1].size() || (t1<kc[st*2].size() && kc[st*2][t1]+a[st*2-1]<kc[st*2+1][t2]+a[st*2])) kc[st].pb(kc[st*2][t1++]+a[st*2-1]);
        else kc[st].pb(kc[st*2+1][t2++]+a[st*2]);
    }
}

void build(int st)
{
    kc[st].pb(0);
    if (st*2>n) return;
    if (st*2<=n) build(st*2);
    if (st*2+1<=n) build(st*2+1);
    megh(st);
    return;
}

void process()
{
    build(1);
    for (int i=1;i<=n;i++)
    {
        ll tmp=0;
        for (int j=0;j<kc[i].size();j++)
        {
            tmp+=kc[i][j];
            cd[i].pb(tmp);
        }
    }
    ll x,p;
    for (int i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&x,&p);
        ll ans=0;
        ll tmp=upper_bound(kc[x].begin(),kc[x].end(),p)-kc[x].begin()-1;
        if (tmp!=-1) ans+=p*(tmp+1)-cd[x][tmp];
        while (x>1)
        {
            ll y=x ^ 1;
            p-=a[x-1];
            if (p>0) ans+=p;
            x/=2;
            tmp=upper_bound(kc[y].begin(),kc[y].end(),p-a[y-1])-kc[y].begin()-1;
            if (tmp!=-1) ans+=(p-a[y-1])*(tmp+1)-cd[y][tmp];
        }
        printf("%I64d\n",ans);
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}