#include"bits/stdc++.h"
using namespace std;
struct node
{
    int L;
    int R;
    int stute;
    node *lnode,*rnode;
};
int a[200005],b[200005];
char s1[200005],s2[200005];
int ans=1;
void add(node &a,int l,int r,int k)
{
    int x=a.L+a.R;
    x/=2;
    if(a.L==l&&a.R==r)
    {
        a.stute=k;
        return;
    }
    else
    {
        if(a.stute!=-1)
        {
            int s=a.stute;
            a.stute=-1;
            if(l!=a.L)
            {
                add(a,a.L,l-1,s);
            }
            if(r!=a.R)
            {
                add(a,r+1,a.R,s);
            }
        }
    }
    if(r<=x)add(*(a.lnode),l,r,k);
    else if(x+1<=l)add(*(a.rnode),l,r,k);
    else
    {
        add(*(a.lnode),l,x,k);
        add(*(a.rnode),x+1,r,k);
    }
}
void creat(node &a)
{
    if(a.L==a.R)
    {
        a.stute=s2[a.L]-'0';
        return;
    }
    else a.stute=-1;
    int x=a.L+a.R;
    x/=2;
    a.lnode=new node;
    a.rnode=new node;
    (a.lnode)->L=a.L;
    (a.lnode)->R=x;
    (a.rnode)->L=x+1;
    (a.rnode)->R=a.R;
    creat(*(a.lnode));
    creat(*(a.rnode));
}
void del(node &a,int k)
{
    if(k==-1&&a.stute!=-1)k=a.stute;
    if(a.L!=a.R)
    {
        del(*(a.lnode),k);
        del(*(a.rnode),k);
        delete a.lnode;
        delete a.rnode;
    }
    else
    {
        if(s1[a.L]-'0'!=k)ans=0;
    }
}
int check(node &a,int l,int r)
{
    int x=a.L+a.R;
    x/=2;//cout<<"??"<<a.L<<" "<<a.R<<endl;
    if(a.stute!=-1)return (r-l+1)*a.stute;
    if(r<=x)return check(*(a.lnode),l,r);
    else if(x+1<=l)return check(*(a.rnode),l,r);
    else
    {
        return check(*(a.lnode),l,x)+check(*(a.rnode),x+1,r);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans=1;
        int n,m;
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
        scanf("%s%s",s1+1,s2+1);
        for(int i=0;i<m;i++)
        {
            scanf("%d",a+i);
            scanf("%d",b+i);
        }
        node root;
        root.L=1;
        root.R=n;
        creat(root);
        for(int i=m-1;i>=0;i--)
        {
            int num=check(root,a[i],b[i]);//cout<<"!!!"<<i<<" "<<num<<endl;
            int sum=b[i]-a[i]+1;
            if(num*2==sum)
            {
                ans=0;
                break;
            }
            else if(num*2>sum)
            {
                add(root,a[i],b[i],1);
            }
            else add(root,a[i],b[i],0);
        }
        del(root,-1);
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
1
1 1
0
0
1 1
*/