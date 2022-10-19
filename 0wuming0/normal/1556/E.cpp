#include"bits/stdc++.h"
using namespace std;
#define ll long long
struct node
{
    int l,r;
    ll op,ans,now;
    node *lc,*rc;
}root,nd[300005];
int nn;
node mge(node &lch,node &rch)
{
    node x;
    x.lc=&lch;
    x.rc=&rch;
    x.l=lch.l;
    x.r=rch.r;
    x.now=lch.now+rch.now;
    x.ans=max(lch.ans,rch.ans-lch.now);
    x.op=max(lch.op,rch.op+lch.now);
    return x;
}
int a[100005],b[100005];
node save[1000];int sn;
void ins(node &p,int l,int r)
{
    if(p.l==l&&p.r==r)
    {
        save[sn++]=p;
        return;
    }
    int x=p.lc->r;
    if(x>=r)
    {
        ins(*p.lc,l,r);
    }
    else if(x<l)
    {
        ins(*p.rc,l,r);
    }
    else
    {
        ins(*p.lc,l,x);
        ins(*p.rc,x+1,r);
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",b+i);
        a[i]-=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        node x;
        x.l=x.r=i;
        x.lc=x.rc=NULL;
        x.op=x.ans=x.now=abs(a[i]);
        x.now=a[i];
        if(a[i]>0)x.ans=0;
        else x.op=0;
        nd[nn++]=x;
    }
    {
        int last=0;
        int now=nn;
        while(1)
        {
            if(now-last==1)break;
            bool flag=0;
            for(int i=last;i<now;i++)
            {
                if(flag)nd[nn++]=mge(nd[i-1],nd[i]);
                flag^=1;
            }
            if(flag)
            {
                nd[nn++]=nd[now-1];
            }
            last=now;
            now=nn;
        }
    }
    node root=nd[nn-1];
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        sn=0;
        ins(root,l,r);
        //for(int i=0;i<sn;i++)cout<<"<<"<<save[i].l<<" "<<save[i].r<<" "<<save[i].ans<<" "<<save[i].op<<" "<<save[i].now<<endl;
        for(int i=0;i<sn-1;i++)
        {
            save[i+1]=mge(save[i],save[i+1]);
        }
        if(save[sn-1].now!=0||save[sn-1].op!=0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",save[sn-1].ans);
        }
    }
    return 0;
}