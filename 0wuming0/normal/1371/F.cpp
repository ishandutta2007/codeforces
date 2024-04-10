#include"bits/stdc++.h"
using namespace std;
char s[500005];
struct node
{
    int ans,ans2;
    int sl1,sr1;
    int sl2,sr2;
    int tag;
    int l,r;
    node *lchild,*rchild;
}root;
void update(node &p)
{
    if(p.tag)
    {
        p.tag=0;
        if(p.lchild)
        {
            p.lchild->tag^=1;
            p.rchild->tag^=1;
        }
        swap(p.ans,p.ans2);
        p.sl1=-p.sl1;
        p.sl2=-p.sl2;
        p.sr1=-p.sr1;
        p.sr2=-p.sr2;
    }
}
void clrans(node &p)
{
    update(*p.lchild);
    update(*p.rchild);
    int t=0;
    p.ans=max(p.lchild->ans,p.rchild->ans);
    p.ans2=max(p.lchild->ans2,p.rchild->ans2);
    if(p.lchild->sr1>0&&p.rchild->sl1>0)
    {
        p.ans=max(p.ans,p.lchild->sr1+p.rchild->sl1-p.rchild->sl2);
        p.ans2=max(p.ans2,p.lchild->sr1+p.rchild->sl1-p.lchild->sr2);
    }
    else if(p.lchild->sr1<0&&p.rchild->sl1<0)
    {
        p.ans=max(p.ans,-p.lchild->sr1-p.rchild->sl1+p.lchild->sr2);
        p.ans2=max(p.ans2,-p.lchild->sr1-p.rchild->sl1+p.rchild->sl2);
    }
    else if(p.lchild->sr1>0&&p.rchild->sl1<0)
    {
        p.ans=max(p.ans,p.lchild->sr1-p.rchild->sl1);
    }
    else
    {
        p.ans2=max(p.ans2,p.rchild->sl1-p.lchild->sr1);
    }
    p.sl1=p.lchild->sl1;
    p.sl2=p.lchild->sl2;
    if(abs(p.sl1)==p.lchild->r-p.lchild->l+1)
    {
        if(p.sl1>0&&p.rchild->sl1>0)
        {
            p.sl1+=p.rchild->sl1;
            p.sl2=p.rchild->sl2;
        }
        else if(p.sl1<0&&p.rchild->sl1<0)
        {
            p.sl1+=p.rchild->sl1;
            p.sl2=p.rchild->sl2;
        }
        else
        {
            p.sl2=p.rchild->sl1;
        }
    }
    else if(abs(p.sl1)+abs(p.sl2)==p.lchild->r-p.lchild->l+1)
    {
        if(p.sl2>0&&p.rchild->sl1>0)
        {
            p.sl2+=p.rchild->sl1;
        }
        else if(p.sl2<0&&p.rchild->sl1<0)
        {
            p.sl2+=p.rchild->sl1;
        }
    }
    p.sr1=p.rchild->sr1;
    p.sr2=p.rchild->sr2;
    if(abs(p.sr1)==p.rchild->r-p.rchild->l+1)
    {
        if(p.sr1>0&&p.lchild->sr1>0)
        {
            p.sr1+=p.lchild->sr1;
            p.sr2=p.lchild->sr2;
        }
        else if(p.sr1<0&&p.lchild->sr1<0)
        {
            p.sr1+=p.lchild->sr1;
            p.sr2=p.lchild->sr2;
        }
        else
        {
            p.sr2=p.lchild->sr1;
        }
    }
    else if(abs(p.sr1)+abs(p.sr2)==p.rchild->r-p.rchild->l+1)
    {
        if(p.sr2>0&&p.lchild->sr1>0)
        {
            p.sr2+=p.lchild->sr1;
        }
        else if(p.sr2<0&&p.lchild->sr1<0)
        {
            p.sr2+=p.lchild->sr1;
        }
    }
}
void creat(node &p)
{
    p.lchild=p.rchild=NULL;
    p.tag=0;
    if(p.l==p.r)
    {
        if(s[p.l]=='<')
        {
            p.sl1=-1;
            p.sr1=-1;
        }
        else
        {
            p.sl1=1;
            p.sr1=1;
        }
        p.sl2=p.sr2=0;
        p.ans=p.ans2=1;
        return;
    }
    p.lchild=new node;
    p.rchild=new node;
    int x=p.l+p.r>>1;
    p.lchild->l=p.l;p.lchild->r=x;
    p.rchild->l=x+1;p.rchild->r=p.r;
    creat(*p.lchild);
    creat(*p.rchild);
    p.tag=0;
    clrans(p);
}
node ans[105];
int nn;
void getans(node &p,int l,int r)
{
    update(p);
    if(p.l==l&&p.r==r)
    {
        p.tag^=1;
        update(p);
        ans[nn++]=p;
        return;
    }
    int x=p.l+p.r>>1;
    if(r<=x)
    {
        getans(*p.lchild,l,r);
    }
    else if(l>x)
    {
        getans(*p.rchild,l,r);
    }
    else
    {
        getans(*p.lchild,l,x);
        getans(*p.rchild,x+1,r);
    }
    clrans(p);
}
int main()
{
    int n,m;
    cin>>n>>m;
    scanf("%s",s+1);
    root.l=1;
    root.r=n;
    creat(root);
    node save;
    while(m--)
    {
        nn=0;
        int l,r;
        scanf("%d%d",&l,&r);
        getans(root,l,r);
        while(nn!=1)
        {
            save.l=ans[nn-2].l;
            save.r=ans[nn-1].r;
            save.lchild=&ans[nn-2];
            save.rchild=&ans[nn-1];
            save.tag=0;
            clrans(save);
            nn--;
            ans[nn-1]=save;
        }
        printf("%d\n",ans[0].ans);
    }
    return 0;
}