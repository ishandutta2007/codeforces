#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
const int N=100005;

int n,m;
int p[N];
int sz[N];
vector<pair<int,int>> v;
set<pair<long,int>> s;

void make_set(int a)
{
    p[a]=a;
    sz[a]=1;
}

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

bool union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return 0;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    return 1;
}

bool mst()
{
    bool res=0;
    for(pair<long,int> p:s)
    {
        if(union_sets(v[p.second].first,v[p.second].second))
        {
            if(p.second==0) res=1;
        }
    }
    return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	long long e;
	for(int i=0;i<m;i++)
    {
        int a,b;
        long long w;
        scanf("%d%d%I64d",&a,&b,&w);
        v.push_back(make_pair(a,b));
        s.insert(make_pair(w,i));
        if(i==0) e=w;
    }
    long long l=-1,r=1000000001;
    while(l<r-1)
    {
        for(int i=1;i<=n;i++) make_set(i);
        long long mid=(l+r)/2;
        s.erase(make_pair(e,0));
        e=mid;
        s.insert(make_pair(e,0));
        if(mst()) l=mid;
        else r=mid;
    }
    printf("%I64d\n",l);
	return 0;
}