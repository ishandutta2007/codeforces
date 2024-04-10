#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
struct node
{
    int l,r;
    int num;
    node *lchild,*rchild;
}root;
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
vector<int*>save;
void ins(node &p,int pos)
{
    p.num--;
    save.push_back(&p.num);
    if(p.l==p.r)
    {
        return;
    }
    int x=p.l+p.r>>1;
    if(x>=pos)
    {
        ins(*p.lchild,pos);
    }
    else
    {
        ins(*p.rchild,pos);
    }
}
int get(node &p,int pos)
{
    if(p.l==p.r)
    {
        return p.l;
    }
    int x=p.l+p.r>>1;
    int k=x-p.l+1+p.lchild->num;
    if(pos<=k)
    {
        return get(*p.lchild,pos);
    }
    else
    {
        return get(*p.rchild,pos-k);
    }
}
int vis[200005];
int solve(int m)
{
    if(m==0)return 0;
    int a;
    scanf("%*d%d",&a);
    int k=solve(m-1);
    int p=get(root,a),q=get(root,a+1);
    if(vis[q]==0)
    {
        vis[q]=1;
        k++;
        save.push_back(vis+q);
    }
    ins(root,p);
    return k;
}
ll jie[400005],dev[400005],devjie[400005];
int main()
{
    jie[0]=devjie[0]=1;jie[1]=devjie[1]=1;dev[1]=1;
    for(int i=2;i<400005;i++)
    {
        jie[i]=jie[i-1]*i%mod;
        dev[i]=(mod-mod/i)*dev[mod%i]%mod;
        devjie[i]=devjie[i-1]*dev[i]%mod;
    }
    root.l=1;
    root.r=200000;
    creat(root);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        m=solve(m);
        for(auto p:save)*p=0;
        save.clear();
        printf("%lld\n",jie[2*n-1-m]*devjie[n]%mod*devjie[n-1-m]%mod);
    }
    return 0;
}