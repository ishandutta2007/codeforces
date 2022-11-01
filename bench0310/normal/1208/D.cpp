#include <bits/stdc++.h>

using namespace std;

const int N=200005;
const long long inf=1000000000000000000;
long long a[N];
long long tree[4*N];
long long lazy[4*N];

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=a[l];
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

void update(int idx,int l,int r,int ql,int qr,long long d)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]+=d;
        lazy[idx]+=d;
    }
    else
    {
        if(lazy[idx]!=0) push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m),d);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,d);
        tree[idx]=min(tree[2*idx],tree[2*idx+1]);
    }
}

long long query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return inf;
    if(l==qr&&r==qr) return tree[idx];
    if(lazy[idx]!=0) push(idx);
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int solve(int idx,int l,int r)
{
    if(l==r) return l;
    if(lazy[idx]!=0) push(idx);
    int m=(l+r)/2;
    if(tree[2*idx+1]==0) return solve(2*idx+1,m+1,r);
    else return solve(2*idx,l,m);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	build(1,1,n);
	int res[n+1];
	for(int i=1;i<=n;i++)
    {
        int idx=solve(1,1,n);
        res[idx]=i;
        update(1,1,n,idx,idx,inf);
        update(1,1,n,idx+1,n,-i);
    }
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}