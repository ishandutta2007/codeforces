#include <bits/stdc++.h>

using namespace std;

const int N=500005;
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

int solve(int idx,int l,int r,int pos)
{
    if(l==r) return l;
    push(idx);
    int m=(l+r)/2;
    if(tree[2*idx]>=pos) return solve(2*idx,l,m,pos);
    else return solve(2*idx+1,m+1,r,pos);
}

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++) v[i]={0,i+1};
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        v[a-1].first++;
    }
    sort(v.begin(),v.end());
    int idx=0;
    vector<pair<long long,int>> queries(q);
    int qidx=0;
    for(int i=0;i<q;i++)
    {
        scanf("%I64d",&queries[i].first);
        queries[i].second=i;
    }
    sort(queries.begin(),queries.end());
    long long day=n;
    long long h=v[0].first;
    int cnt=0;
    vector<int> res(q);
    while(h<=v.back().first)
    {
        while(idx<m&&v[idx].first==h)
        {
            update(1,1,m,v[idx].second,m);
            cnt++;
            idx++;
        }
        while(qidx<q&&day+1<=queries[qidx].first&&queries[qidx].first<=day+cnt)
        {
            res[queries[qidx].second]=solve(1,1,m,queries[qidx].first-day);
            qidx++;
        }
        day+=cnt;
        h++;
    }
    while(qidx<q)
    {
        res[queries[qidx].second]=(queries[qidx].first-day-1)%m+1;
        qidx++;
    }
    for(int a:res) printf("%d\n",a);
    return 0;
}