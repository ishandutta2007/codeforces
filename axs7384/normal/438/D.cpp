#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<string.h>  
#include<math.h>  
#include<algorithm>  
#include<map>  
#include<vector>  
#include<queue>  
using namespace std;  
#define MAXN 100005  
struct node  
{  
    int l,r;  
    int mid;  
    long long maxx;  
    long long sum;  
}tree[MAXN<<2];  
void build(int l,int r,int now)  
{  
    tree[now].l=l;  
    tree[now].r=r;  
    tree[now].mid=(l+r)>>1;  
    if(l==r)  
    {  
        scanf("%I64d",&tree[now].maxx);  
        tree[now].sum=tree[now].maxx;  
        return ;  
    }  
    build(l,tree[now].mid,now<<1);  
    build(tree[now].mid+1,r,now<<1|1);  
    tree[now].sum=(tree[now<<1].sum+tree[now<<1|1].sum);  
    tree[now].maxx=max(tree[now<<1].maxx,tree[now<<1|1].maxx);  
}  
long long query(int l,int r,int now)  
{  
    if(tree[now].l==l && tree[now].r==r)  
        return tree[now].sum;  
    if(l>tree[now].mid)  
        return query(l,r,now<<1|1);  
    else if(r<=tree[now].mid)  
        return query(l,r,now<<1);  
    else  
        return query(l,tree[now].mid,now<<1)+query(tree[now].mid+1,r,now<<1|1);  
}  
void update(int l,int r,long long x,int now)  
{  
    if(tree[now].maxx<x)  
        return ;  
    if(tree[now].l==tree[now].r)  
    {  
        tree[now].sum=tree[now].sum%x;  
        tree[now].maxx=tree[now].sum;  
        return ;  
    }  
    if(l>tree[now].mid)  
        update(l,r,x,now<<1|1);  
    else if(r<=tree[now].mid)  
        update(l,r,x,now<<1);  
    else  
    {  
        update(l,tree[now].mid,x,now<<1);  
        update(tree[now].mid+1,r,x,now<<1|1);  
    }  
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;  
    tree[now].maxx=max(tree[now<<1].maxx,tree[now<<1|1].maxx);  
}  
void op3(int k,long long x,int now)  
{  
    if(tree[now].l==k && tree[now].r==k)  
    {  
        tree[now].maxx=tree[now].sum=x;  
        return ;  
    }  
    if(k>tree[now].mid)  
        op3(k,x,now<<1|1);  
    else  
        op3(k,x,now<<1);  
    tree[now].sum=(tree[now<<1].sum+tree[now<<1|1].sum);  
    tree[now].maxx=max(tree[now<<1].maxx,tree[now<<1|1].maxx);  
}  
int main()  
{  
    int n,m;  
    cin>>n>>m;  
    build(1,n,1);  
    while(m--)  
    {  
        int op;  
        scanf("%d",&op);  
        if(op==1)  
        {  
            int l,r;  
            scanf("%d%d",&l,&r);  
            cout<<query(l,r,1)<<endl;  
        }  
        else if(op==2)  
        {  
            int l,r;  
            long long x;  
            scanf("%d%d%I64d",&l,&r,&x);  
            update(l,r,x,1);  
        }  
        else if(op==3)  
        {  
            int k;  
            long long x;  
            scanf("%d%I64d",&k,&x);  
            op3(k,x,1);  
        }  
    }  
    return 0;  
}