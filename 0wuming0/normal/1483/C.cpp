#include"bits/stdc++.h"
using namespace std;
#define ll long long
int n;
int h[300005];
int b[300005];
struct node
{
    int l;
    int r;
    int num;
    node *lchild,*rchild;
}root;
void creat(node &p)
{
    if(p.l==p.r)
    {
        p.num=p.l;
        p.lchild=p.rchild=NULL;
        return;
    }
    int x=(p.l+p.r)/2;
    p.lchild=new node;
    p.rchild=new node;
    (p.lchild)->l=p.l;
    (p.lchild)->r=x;
    (p.rchild)->l=x+1;
    (p.rchild)->r=p.r;
    creat(*(p.lchild));
    creat(*(p.rchild));
    int xx=(p.lchild)->num;
    int yy=(p.rchild)->num;
    if(h[xx]<h[yy])p.num=xx;
    else p.num=yy;
}
int fd2(node &p,int l,int r)
{
    if(p.l==l&&p.r==r)
    {
        return p.num;
    }
    int x=(p.l+p.r)/2;
    if(r<=x)
    {
        return fd2(*(p.lchild),l,r);
    }
    else if(x+1<=l)
    {
        return fd2(*(p.rchild),l,r);
    }
    else
    {
        int aa=fd2(*(p.lchild),l,x);
        int bb=fd2(*(p.rchild),x+1,r);
        if(h[aa]<h[bb])return aa;
        else return bb;
    }
}
int fd(int l,int r)
{
    return fd2(root,l,r);
}
ll solve(int l,int r,int op)
{
    if(l>r)return 0;
    if(l==r)return max(0,b[l]);
    int m=fd(l,r);
    ll ansl,ansr;
    if(op==0)
    {
        ansl=solve(l,m-1,0);
        ansr=solve(m+1,r,0);
        return max(max(ansl,ansr),max(0ll,b[m]+ansl+ansr));
    }
    else if(op==1)
    {
        ansl=solve(l,m-1,1);
        ansr=solve(m+1,r,0);
        return max(max(ansl,0ll),max(0ll,b[m]+ansl+ansr));
    }
    else if(op==2)
    {
        ansl=solve(l,m-1,0);
        ansr=solve(m+1,r,2);
        return max(max(ansr,0ll),max(0ll,b[m]+ansl+ansr));
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",h+i);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    root.l=1;
    root.r=n;
    creat(root);
    /*
    while(1)
    {
        int x,y;
        cin>>x>>y;
        cout<<fd(x,y)<<endl;
    }*/
    ll ans=0;
    int m=fd(1,n);
    ans+=b[m];
    ans+=solve(1,m-1,1);
    ans+=solve(m+1,n,2);
    cout<<ans<<endl;
    return 0;
}