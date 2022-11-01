#include <bits/stdc++.h>

using namespace std;

const int N=300005;
int tree[4*N];
int a[N];

void build(int idx,int l,int r)
{
    if(l==r) tree[idx]=a[l];
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return max(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int up(int a)
{
    return (a+1)/2;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i+2*n]=a[i];
    }
    int m=3*n;
    build(1,1,m);
    vector<pair<int,int>> v;
    for(int i=1;i<=3*n;i++)
    {
        if(a[i]>=up(query(1,1,m,1,i))) continue;
        int l=1,r=i+1;
        while(l<r-1)
        {
            int mid=(l+r)/2;
            if(a[i]<up(query(1,1,m,mid,i))) l=mid;
            else r=mid;
        }
        v.push_back({l,i});
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    int idx=0;
    int t=m+1;
    vector<int> res(n+1,-1);
    for(int i=n;i>=1;i--)
    {
        while(idx<(int)v.size()&&v[idx].first>=i)
        {
            t=min(t,v[idx].second);
            idx++;
        }
        if(t!=m+1) res[i]=(t-i);
    }
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}