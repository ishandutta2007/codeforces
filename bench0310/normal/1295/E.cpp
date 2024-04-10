#include <bits/stdc++.h>

using namespace std;

const long long inf=1000000000000000000;
const int N=200005;
long long tree[4*N];
long long lazy[4*N];

void push(int idx)
{
    tree[2*idx]+=lazy[idx];
    lazy[2*idx]+=lazy[idx];
    tree[2*idx+1]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr,long long val)
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

long long query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return inf;
    if(l==ql&&r==qr) return tree[idx];
    push(idx);
    int m=(l+r)/2;
    return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> p(n+1,0);
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    vector<long long> a(n+1,0);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    long long zero=0;
    for(int i=1;i<=n;i++) update(1,1,n,i,n,a[i]);
    long long res=inf;
    for(int k=0;k<=n;k++)
    {
        if(k>0)
        {
            zero+=a[pos[k]];
            update(1,1,n,pos[k],n,-2ll*a[pos[k]]);
        }
        res=min(res,zero+query(1,1,n,1,n-1));
    }
    printf("%I64d\n",res);
    return 0;
}