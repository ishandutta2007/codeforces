#include"bits/stdc++.h"
using namespace std;
int a[300005];
int b[300005];
vector<int>va[300005],vb[300005];
int pos[300005],nn;
int l[300005],r[300005];
void inti(int i)
{
    pos[i]=l[i]=++nn;
    for(auto j:vb[i])
    {
        inti(j);
    }
    r[i]=nn;
}
struct node
{
    int l,r,num,lay,c;
    node *lchild,*rchild;
}root;
void creat(node &p)
{
    p.num=p.lay=p.c=0;
    p.lchild=p.rchild=NULL;
    if(p.l!=p.r)
    {
        int x=p.l+p.r>>1;
        p.lchild=new node;
        p.rchild=new node;
        p.lchild->l=p.l;
        p.lchild->r=x;
        p.rchild->l=x+1;
        p.rchild->r=p.r;
        creat(*(p.lchild));
        creat(*(p.rchild));
    }
}
void update(node &p)
{
    if(p.lay==0)return;
    if(p.l!=p.r)
    {
        p.lchild->lay=p.lay;
        p.rchild->lay=p.lay;
        p.lchild->c=p.c;
        p.rchild->c=p.c;
    }
    if(p.lay==1)
    {
        p.num=p.r-p.l+1;
    }
    else p.num=0;
    p.lay=0;
}
void sets(node &p,int l,int r,int op,int c)
{
    update(p);
    if(p.l==l&&p.r==r)
    {
        p.lay=op;
        p.c=c;
        return;
    }
    p.num+=op*(r-l+1);
    int x=p.l+p.r>>1;
    if(x>=r)
    {
        sets(*p.lchild,l,r,op,c);
    }
    else if(x<l)
    {
        sets(*p.rchild,l,r,op,c);
    }
    else
    {
        sets(*p.lchild,l,x,op,c);
        sets(*p.rchild,x+1,r,op,c);
    }
}
int fd(node &p,int l,int r)
{
    update(p);
    if(p.l==l&&p.r==r)
    {
        return p.num;
    }
    int x=p.l+p.r>>1;
    if(x>=r)
    {
        return fd(*p.lchild,l,r);
    }
    else if(x<l)
    {
        return fd(*p.rchild,l,r);
    }
    else
    {
        return fd(*p.lchild,l,x)+fd(*p.rchild,x+1,r);
    }
}
int fdc(node &p,int pos)
{
    update(p);
    if(p.l==pos&&p.r==pos)
    {
        return p.c;
    }
    int x=p.l+p.r>>1;
    if(x>=pos)
    {
        return fdc(*p.lchild,pos);
    }
    else if(x<pos)
    {
        return fdc(*p.rchild,pos);
    }
}
int ans,now;
void solve(int i)
{
    int k=fdc(root,l[i]);
    if(k)
    {//cout<<"<<<"<<"-"<<k<<"+"<<i<<endl;
        sets(root,l[k],r[k],-1,0);
        sets(root,l[i],r[i],1,i);
        for(auto j:va[i])
        {
            solve(j);
        }
        sets(root,l[i],r[i],-1,0);
        sets(root,l[k],r[k],1,k);
    }
    else if(fd(root,l[i],r[i])==0)
    {//cout<<"<<<"<<"+"<<i<<endl;
        sets(root,l[i],r[i],1,i);
        now++;
        ans=max(ans,now);
        for(auto j:va[i])
        {
            solve(j);
        }
        now--;
        sets(root,l[i],r[i],-1,0);
    }
    else
    {//cout<<"<<<"<<"x"<<i<<endl;
        for(auto j:va[i])
        {
            solve(j);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            va[i].clear();
            vb[i].clear();
            a[i]=b[i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            scanf("%d",a+i);
            va[a[i]].push_back(i);
        }
        for(int i=2;i<=n;i++)
        {
            scanf("%d",b+i);
            vb[b[i]].push_back(i);
        }
        nn=0;
        inti(1);
        root.l=1;
        root.r=n;
        creat(root);
        ans=now=0;
        solve(1);
        printf("%d\n",ans);
    }
    return 0;
}