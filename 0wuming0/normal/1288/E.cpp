#include"bits/stdc++.h"
using namespace std;
struct node
{
    int l,r;
    int num;
    node *lchild,*rchild;
}root;
int n,m;
void creat(node &p)
{
    p.num=0;
    p.lchild=p.rchild=NULL;
    if(p.l==p.r)
    {
        p.num=n+m-p.l;
        return;
    }
    p.lchild=new node;
    p.rchild=new node;
    int x=p.l+p.r>>1;
    p.lchild->l=p.l;p.lchild->r=x;
    p.rchild->l=x+1;p.rchild->r=p.r;
    creat(*p.lchild);
    creat(*p.rchild);
}
void del(node &p,int l,int r)
{//cout<<p.l<<" "<<p.r<<" "<<l<<" "<<r<<endl;
    if(l==p.l&&r==p.r)
    {
        p.num--;
        return;
    }
    int x=p.l+p.r>>1;
    if(x>=r)
    {
        del(*p.lchild,l,r);
    }
    else if(x<l)
    {
        del(*p.rchild,l,r);
    }
    else
    {
        del(*p.lchild,l,x);
        del(*p.rchild,x+1,r);
    }
}
int fd(node &p,int pos,int last)
{
    if(p.l==p.r)
    {
        return p.num+last;
    }
    int x=p.l+p.r>>1;
    if(x>=pos)
    {
        return fd(*p.lchild,pos,last+p.num);
    }
    else
    {
        return fd(*p.rchild,pos,last+p.num);
    }
}
int ansl[300005],ansr[300005];
int main()
{
    cin>>n>>m;
    root.l=1;
    root.r=n+m;
    creat(root);
    map<int,int>mp1,mp2;
    int now=n+m;
    for(int i=n;i>=1;i--)
    {
        mp1[i]=now;
        mp2[now]=i;
        now--;
        ansl[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int a;
        scanf("%d",&a);
        mp2.erase(mp2.find(mp1[a]));
        ansr[a]=max(ansr[a],n-fd(root,mp1[a],0));
        del(root,1,mp1[a]);//cout<<"ok"<<endl;
        mp2[now]=a;
        mp1[a]=now;
        now--;
        ansl[a]=1;
    }
    //cout<<now<<endl;
    for(auto pr:mp1)
    {
        ansr[pr.first]=max(ansr[pr.first],n-fd(root,pr.second,0));
    }
    for(int i=1;i<=n;i++)printf("%d %d\n",ansl[i],ansr[i]);
    return 0;
}