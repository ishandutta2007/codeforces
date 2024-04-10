#include"bits/stdc++.h"
using namespace std;
struct node
{
    int num,l,r;
    node *lchild,*rchild;
};
void creat(node &p)
{
    p.num=0;
    if(p.l==p.r)
    {
        p.lchild=p.rchild=NULL;
        return;
    }
    int x=p.l+p.r>>1;
    p.lchild=new node;
    p.rchild=new node;
    p.lchild->l=p.l;p.lchild->r=x;
    p.rchild->l=x+1;p.rchild->r=p.r;
    creat(*p.lchild);
    creat(*p.rchild);
}
void ins(node &p,int x)
{
    p.num++;
    if(p.l==p.r)return;
    int m=p.l+p.r>>1;
    if(x<=m)ins(*p.lchild,x);
    else ins(*p.rchild,x);
}
int gt(node &p,int x)
{
    if(x==p.r)
    {
        return p.num;
    }
    int m=p.l+p.r>>1;
    if(x<=m)return gt(*p.lchild,x);
    else return gt(*p.rchild,x)+p.lchild->num;
}
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            mp[a[i]]=1;
        }
        map<int,int>s;
        int cnt=0;
        for(auto &pr:mp)pr.second=++cnt;
        long long ans=0;
        node root;
        root.l=1;
        root.r=cnt;
        creat(root);
        for(int i=1;i<=n;i++)
        {
            int c,b;
            c=gt(root,mp[a[i]]);
            b=i-1-c;
            if(s.find(a[i])!=s.end())c-=s[a[i]]++;
            else s[a[i]]=1;
            ans+=min(b,c);
            ins(root,mp[a[i]]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}