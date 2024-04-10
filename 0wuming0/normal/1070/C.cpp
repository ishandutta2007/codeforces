#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[1000005];
struct node
{
    int l,r;
    int num;
    ll des,mins;
    node *lchild,*rchild;
}root;
void creat(node &p)
{
    p.des=0;
    if(p.l==p.r)
    {
        p.lchild=p.rchild=NULL;
        if(a[p.l]==0)
        {
            p.num=0;
            p.mins=2e18;
        }
        else
        {
            p.num=1;
            p.mins=a[p.l];
        }
        return;
    }
    int x=p.l+p.r>>1;
    p.lchild=new node;
    p.rchild=new node;
    p.lchild->l=p.l;p.lchild->r=x;
    p.rchild->l=x+1;p.rchild->r=p.r;
    creat(*p.lchild);
    creat(*p.rchild);
    p.mins=min(p.lchild->mins,p.rchild->mins);
    p.num=p.lchild->num+p.rchild->num;
}
void clr(node &p)
{
    if(p.des)
    {
        if(p.lchild)
        {
            p.lchild->des+=p.des;
            p.rchild->des+=p.des;
            p.lchild->mins-=p.des;
            p.rchild->mins-=p.des;
        }
        p.des=0;
    }
}
ll updata(node &p,ll k)
{
    if(p.num==0)return 0;clr(p);
    if(k<p.mins)
    {
        p.mins-=k;
        p.des+=k;
        return p.num*k;
    }
    if(p.lchild)
    {
        ll ans=updata(*p.lchild,k)+updata(*p.rchild,k);
        p.mins=min(p.lchild->mins,p.rchild->mins);
        p.num=p.lchild->num+p.rchild->num;
        return ans;
    }
    else
    {
        p.num=0;
        ll ans=p.mins;
        p.mins=2e18;
        return ans;
    }
}
ll ins(node &p,int l,int r,ll k)
{
    if(p.num==0)return 0;clr(p);
    if(p.l==l&&p.r==r)
    {
        return updata(p,k);
    }
    int x=p.l+p.r>>1;
    if(x>=r)
    {
        ll ans=ins(*p.lchild,l,r,k);
        p.mins=min(p.lchild->mins,p.rchild->mins);
        p.num=p.lchild->num+p.rchild->num;
        return ans;
    }
    else if(x<l)
    {
        ll ans=ins(*p.rchild,l,r,k);
        p.mins=min(p.lchild->mins,p.rchild->mins);
        p.num=p.lchild->num+p.rchild->num;
        return ans;
    }
    else
    {
        ll ans=ins(*p.lchild,l,x,k)+ins(*p.rchild,x+1,r,k);
        p.mins=min(p.lchild->mins,p.rchild->mins);
        p.num=p.lchild->num+p.rchild->num;
        return ans;
    }
}
struct _
{
    int l,r;
    ll c,p;
}pl[200005];
bool cmp(_ x,_ y)
{
    return x.p>y.p;
}
int main()
{
    ll ans=0;
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%lld%lld",&pl[i].l,&pl[i].r,&pl[i].c,&pl[i].p);
        ans+=(pl[i].r-pl[i].l+1)*pl[i].c*pl[i].p;
        a[pl[i].l]+=pl[i].c;
        a[pl[i].r+1]-=pl[i].c;
    }
    for(int i=1;i<1000005;i++)a[i]+=a[i-1];
    for(int i=1;i<1000005;i++)
    {
        a[i]-=k;
        if(a[i]<0)a[i]=0;
    }
    root.l=1;root.r=n;//cout<<"ok"<<endl;
    creat(root);
    sort(pl,pl+m,cmp);
    for(int i=0;i<m;i++)
    {
        ll now=ins(root,pl[i].l,pl[i].r,pl[i].c);
        //cout<<"???"<<pl[i].l<<" "<<pl[i].r<<" "<<pl[i].c<<" "<<pl[i].p<<"  "<<now<<endl;
        ans-=now*pl[i].p;
    }
    cout<<ans<<endl;
    return 0;
}