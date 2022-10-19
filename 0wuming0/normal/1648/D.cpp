#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a1[500005],a2[500005],a3[500005];
ll sum1[500005],sum2[500005],sum3[500005];
struct sale
{
    ll l,r,w;
}b[500005];
bool cmp(sale x,sale y)
{
    return x.l<y.l;
}
struct node
{
    int l,r;
    ll ans;
    ll base;
    ll sk;
    ll s;
}nd[1500005];
void init(int i,int l,int r)
{
    node &p=nd[i];
    node &pl=nd[i*2];
    node &pr=nd[i*2+1];
    p.l=l;
    p.r=r;
    p.ans=-1e18;
    p.s=p.sk=-1e18;
    if(l==r)
    {
        p.base=sum1[l]+sum2[l];
        return;
    }
    int m=l+r>>1;
    init(i*2,l,m);
    init(i*2+1,m+1,r);
    p.base=max(pl.base,pr.base);
}
void updata(int i)
{
    node &p=nd[i];
    if(p.l==p.r)
    {
        p.ans=max(p.ans,p.s);
        p.ans=max(p.ans,p.base+p.sk);
        return;
    }
    node &pl=nd[i*2];
    node &pr=nd[i*2+1];
    pl.s=max(pl.s,p.s);
    pr.s=max(pr.s,p.s);
    pl.sk=max(pl.sk,p.sk);
    pr.sk=max(pr.sk,p.sk);
    pr.s=max(max(pl.s,max(pl.ans,pl.base))+p.sk,pr.s);
    p.ans=max(p.ans,p.s);
    p.ans=max(p.ans,p.base+p.sk);
}
ll solve(int i,int l,int r,ll k,ll now)
{
    node &p=nd[i];
    updata(i);
    if(p.l==l&&p.r==r)
    {
        p.s=max(p.s,now+k);
        p.sk=max(p.sk,k);
        now=max(p.ans,now);
        now=max(p.base,now);
        return now;
    }
    int m=p.l+p.r>>1;
    if(m>=r)
    {
        return solve(i*2,l,r,k,now);
    }
    else if(m<l)
    {
        return solve(i*2+1,l,r,k,now);
    }
    else
    {
        now=max(solve(i*2,l,m,k,now),now);
        return solve(i*2+1,m+1,r,k,now);
    }
}
ll get(int i,int pos)
{
    node &p=nd[i];
    updata(i);
    if(p.l==p.r)
    {
        return p.ans;
    }
    int m=p.l+p.r>>1;
    if(m>=pos)
    {
        return get(i*2,pos);
    }
    else if(m<pos)
    {
        return get(i*2+1,pos);
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a1+i);
        sum1[i]=sum1[i-1]+a1[i];
    }
    for(int i=1;i<=n;i++)scanf("%lld",a2+i);
    for(int i=1;i<=n;i++)scanf("%lld",a3+i);
    for(int i=n;i>=1;i--)
    {
        sum2[i]=sum2[i+1]+a2[i];
        sum3[i]=sum3[i+1]+a3[i];
    }
    for(int i=0;i<q;i++)scanf("%lld%lld%lld",&b[i].l,&b[i].r,&b[i].w);
    sort(b,b+q,cmp);
    init(1,0,n);
    for(int i=0;i<q;i++)
    {
        solve(1,b[i].l,b[i].r,-b[i].w,get(1,b[i].l-1));
        //cout<<"<<<"<<i<<" "<<b[i].l<<" "<<b[i].r<<" " <<b[i].w<<endl;
        //for(int i=1;i<=n;i++)printf("%lld%c",get(1,i)," \n"[i==n]);
    }
    ll sum=-1e18;
    for(int i=1;i<=n;i++)
    {
        sum=max(sum,get(1,i)-sum2[i+1]+sum3[i]);
    }
    cout<<sum<<endl;
    return 0;
}