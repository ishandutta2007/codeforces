#include"bits/stdc++.h"
using namespace std;
struct node
{
    int l,r;
    int now1,now2;
    int ans;
    node *lchild,*rchild;
}root;
void clr(node &p,int l,int r)
{
    p.l=l;
    p.r=r;
    p.lchild=p.rchild=0;
    p.now1=0;
    p.now2=0;
}
void creat(node &p)
{
    if(p.l==p.r)return;
    p.lchild=new node;
    p.rchild=new node;
    int x=(p.l+p.r)/2;
    clr(*(p.lchild),p.l,x);
    clr(*(p.rchild),x+1,p.r);
    creat(*(p.lchild));
    creat(*(p.rchild));
}
void change(node &p)
{
    p.now2=(p.lchild)->now2;
    p.now1=(p.rchild)->now1;
    if((p.lchild)->now1>(p.rchild)->now2)p.now1+=(p.lchild)->now1-(p.rchild)->now2;
    else p.now2-=(p.lchild)->now1-(p.rchild)->now2;
}
void add1(node &p,int a)
{
    if(p.l==p.r)
    {
        if(p.now2>0)p.now2--;
        else p.now1++;
        return;
    }
    int x=(p.l+p.r)/2;
    if(a<=x)add1(*(p.lchild),a);
    else add1(*(p.rchild),a);
    change(p);
}
void add2(node &p,int a)
{
    if(p.l==p.r)
    {
        if(p.now1>0)p.now1--;
        else p.now2++;
        return;
    }
    int x=(p.l+p.r)/2;
    if(a<=x)add2(*(p.lchild),a);
    else add2(*(p.rchild),a);
    change(p);
}
void del1(node &p,int a)
{
    if(p.l==p.r)
    {
        if(p.now1>0)p.now1--;
        else p.now2++;
        return;
    }
    int x=(p.l+p.r)/2;
    if(a<=x)del1(*(p.lchild),a);
    else del1(*(p.rchild),a);
    change(p);
}
void del2(node &p,int a)
{
    if(p.l==p.r)
    {
        if(p.now2>0)p.now2--;
        else p.now1++;
        return;
    }
    int x=(p.l+p.r)/2;
    if(a<=x)del2(*(p.lchild),a);
    else del2(*(p.rchild),a);
    change(p);
}
void serch(node &p,int now)
{
    if(p.now1<=now)
    {
        printf("-1\n");
    }
    else if(p.l==p.r)
    {
        printf("%d\n",p.l);
    }
    else if((p.rchild)->now1>now)
    {
        serch(*(p.rchild),now);
    }
    else
    {
        serch(*(p.lchild),now-(p.rchild)->now1+(p.rchild)->now2);
    }
}
int a[300005];
int b[300005];
int main()
{
    clr(root,1,1e6);
    creat(root);
    int n,m,q;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i);
    for(int i=1;i<=n;i++)add1(root,a[i]);
    for(int i=1;i<=m;i++)add2(root,b[i]);
    cin>>q;
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)
        {
            del1(root,a[y]);
            add1(root,z);
            a[y]=z;
        }
        else
        {
            del2(root,b[y]);
            add2(root,z);
            b[y]=z;
        }
        serch(root,0);
    }
    return 0;
}
/*
3 3
1 2 2
1 2 2
1
1 1 1
*/