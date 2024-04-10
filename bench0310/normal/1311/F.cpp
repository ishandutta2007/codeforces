#include <bits/stdc++.h>

using namespace std;

const int N=200005;
long long cnt[4*N];
long long tree[4*N];

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r)
    {
        cnt[idx]++;
        tree[idx]+=val;
    }
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        cnt[idx]=cnt[2*idx]+cnt[2*idx+1];
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

pair<long long,long long> query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return {0,0};
    if(l==ql&&r==qr) return {cnt[idx],tree[idx]};
    int m=(l+r)/2;
    pair<long long,long long> one=query(2*idx,l,m,ql,min(qr,m));
    pair<long long,long long> two=query(2*idx+1,m+1,r,max(ql,m+1),qr);
    return {one.first+two.first,one.second+two.second};
}

long long solve(vector<pair<int,int>> v)
{
    int n=v.size();
    set<int> s;
    for(pair<int,int> p:v) s.insert(p.second);
    map<int,int> m;
    int idx=1;
    for(int t:s) m[t]=idx++;
    for(pair<int,int> &p:v) p.second=m[p.second];
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    long long res=0;
    for(auto [x,t]:v)
    {
        auto [c,sum]=query(1,1,n,t,n);
        res+=(sum-c*x);
        update(1,1,n,t,x);
    }
    for(int i=0;i<4*N;i++) cnt[i]=tree[i]=0;
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    vector<pair<int,int>> v(n);
    vector<pair<int,int>> pos,neg;
    for(int i=0;i<n;i++)
    {
        v[i]={a[i],b[i]};
        if(b[i]>0||b[i]==0) pos.push_back({a[i],b[i]});
        if(b[i]<0||b[i]==0) neg.push_back({100000001-a[i],-b[i]});
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    //zero
    long long c=0;
    long long sum=0;
    long long temp=0;
    for(auto [x,t]:v)
    {
        if(t!=0) continue;
        temp+=(sum-c*x);
        c++;
        sum+=x;
    }
    //pos+neg
    c=sum=0;
    long long res=0;
    for(auto [x,t]:v)
    {
        if(t==0) continue;
        if(t>0)
        {
            c++;
            sum+=x;
        }
        else res+=(sum-c*x);
    }
    printf("%I64d\n",res+solve(pos)+solve(neg)-temp);
    return 0;
}