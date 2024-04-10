#include <bits/stdc++.h>

using namespace std;

const int N=200005;
int tree[4*N];
int lazy[4*N];

void push(int idx)
{
    tree[2*idx]+=lazy[idx];
    lazy[2*idx]+=lazy[idx];
    tree[2*idx+1]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        tree[idx]++;
        lazy[idx]++;
    }
    else
    {
        push(idx);
        int m=(l+r)/2;
        update(2*idx,l,m,ql,min(qr,m));
        update(2*idx+1,m+1,r,max(ql,m+1),qr);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int solve(int idx,int l,int r,int k)
{
    if(l==r) return l;
    push(idx);
    int m=(l+r)/2;
    if(tree[2*idx]>=k) return solve(2*idx,l,m,k);
    else return solve(2*idx+1,m+1,r,k);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        v[i]={a[i],i+1};
    }
    sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){return (a.first>b.first)||(a.first==b.first&&a.second<b.second);});
    int m;
    scanf("%d",&m);
    vector<pair<int,int>> t[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        t[a].push_back({b,i});
    }
    vector<int> res(m);
    for(int o=1;o<=n;o++)
    {
        update(1,1,n,v[o-1].second,n);
        for(pair<int,int> p:t[o]) res[p.second]=a[solve(1,1,n,p.first)-1];
    }
    for(int i=0;i<m;i++) printf("%d\n",res[i]);
    return 0;
}