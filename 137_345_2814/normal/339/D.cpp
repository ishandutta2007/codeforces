#include<cstdio>
#include<algorithm>
using namespace std;
struct ed{
    int l,r,ans;
}e[560000];
int v[140000],n,k,a,b,cnt;
void build(int m,int l,int r,int dep)
{
    if(l==r)
    {
        e[m].l=e[m].r=l;
        e[m].ans=v[++cnt];
        return;
    }
    int mid=(l+r)>>1;
    build(m<<1,l,mid,dep+1);
    build(m<<1|1,mid+1,r,dep+1);
    e[m].l=l;
    e[m].r=r;
    if((n-dep)&1)
    e[m].ans=e[m<<1].ans^e[m<<1|1].ans;
    else
    e[m].ans=e[m<<1].ans|e[m<<1|1].ans;
    return;
}
void update(int m,int dep,int s,int p)
{
    if(e[m].l==e[m].r)
    {
        if(e[m].l==s)
        e[m].ans=p;
        return;
    }
    int mid=(e[m].l+e[m].r)>>1;
    if(mid<s)
    update(m<<1|1,dep+1,s,p);
    else
    update(m<<1,dep+1,s,p);
    if((n-dep)&1)
    e[m].ans=e[m<<1].ans^e[m<<1|1].ans;
    else
    e[m].ans=e[m<<1].ans|e[m<<1|1].ans;
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=(1<<n);i++)
    scanf("%d",&v[i]);
    build(1,1,1<<n,1);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&a,&b);
        update(1,1,a,b);
        printf("%d\n",e[1].ans);
    }
    return 0;
}