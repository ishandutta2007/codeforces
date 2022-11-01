#include <bits/stdc++.h>

using namespace std;
const int N=1000000;
const int inf=1000000000;

int tree[4*N],lazy[4*N];
int dishes[N+1],pupils[N+1];
int arr[N+1];

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=arr[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

void push(int idx)
{
    tree[2*idx]+=lazy[idx];
    lazy[2*idx]+=lazy[idx];
    tree[2*idx+1]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return inf;
    if(l==ql&&r==qr) return tree[idx];
    push(idx);
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

void update(int idx,int l,int r,int ql,int qr,int val)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=val;
        lazy[idx]+=val;
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),val);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,val);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> a(n+1),b(m+1);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dishes[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        pupils[b[i]]++;
    }
    vector<int> one(N+1,dishes[N]),two(N+1,pupils[N]);
    for(int i=N-1;i>=1;i--)
    {
        one[i]=one[i+1]+dishes[i];
        two[i]=two[i+1]+pupils[i];
    }
    for(int i=1;i<=N;i++) arr[i]=two[i]-one[i];
    build(1,1,N);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t,id,x;
        scanf("%d%d%d",&t,&id,&x);
        if(t==1)
        {
            update(1,1,N,1,a[id],1);
            a[id]=x;
            update(1,1,N,1,x,-1);
        }
        else
        {
            update(1,1,N,1,b[id],-1);
            b[id]=x;
            update(1,1,N,1,x,1);
        }
        if(query(1,1,N,1,N)>=0) printf("-1\n");
        else
        {
            int l=1,r=N+1;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(query(1,1,N,m,N)<0) l=m;
                else r=m;
            }
            printf("%d\n",l);
        }
    }
	return 0;
}