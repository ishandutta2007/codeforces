#include <bits/stdc++.h>

using namespace std;
const int N=200005;

int tree[4*N];

void update(int idx,int l,int r,int pos)
{
    if(l==r) tree[idx]=1;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return query(2*idx,l,m,ql,min(qr,m))+query(2*idx+1,m+1,r,max(ql,m+1),qr);
}

long long sum(long long a)
{
    return (a*(a+1)/2ll);
}

int main()
{
    int n;
    scanf("%d",&n);
	vector<pair<int,int>> v;
	set<int> s;
	map<int,int> m;
	for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(y,x));
        s.insert(x);
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    int id=1;
    for(int a:s) m.insert(make_pair(a,id++));
    int idx=0;
    long long res=0;
    while(idx<n)
    {
        int now=v[idx].first;
        vector<int> t;
        while(idx<n&&v[idx].first==now) t.push_back(v[idx++].second);
        reverse(t.begin(),t.end());
        for(int i=0;i<(int)t.size();i++) update(1,1,n,m[t[i]]);
        long long cnt=sum(query(1,1,n,1,n));
        cnt-=sum(query(1,1,n,1,m[t[0]]-1));
        cnt-=sum(query(1,1,n,m[t.back()]+1,n));
        for(int i=0;i<(int)t.size()-1;i++) cnt-=sum(query(1,1,n,m[t[i]]+1,m[t[i+1]]-1));
        res+=cnt;
    }
    printf("%I64d\n",res);
	return 0;
}