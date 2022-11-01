#include <bits/stdc++.h>

using namespace std;

const int N=200005;
int p[N];
int sz[N];
long long cnt=0;

long long pairs(long long a)
{
    return (a*(a-1)/2);
}

void make_set(int a)
{
    p[a]=a;
    sz[a]=1;
}

int find_set(int a)
{
    if(p[a]==a) return a;
    else return p[a]=find_set(p[a]);
}

void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    cnt-=(pairs(sz[a])+pairs(sz[b]));
    p[b]=a;
    sz[a]+=sz[b];
    cnt+=pairs(sz[a]);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) make_set(i);
	vector<pair<int,int>> edges(n-1);
	vector<pair<int,int>> v(n-1);
	for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i]={a,b};
        v[i]={c,i};
    }
    sort(v.begin(),v.end());
    vector<long long> res(N);
    int now=1;
    for(pair<int,int> t:v)
    {
        int w=t.first;
        int a,b;
        tie(a,b)=edges[t.second];
        while(now<w) res[now++]=cnt;
        union_sets(a,b);
    }
    while(now<N) res[now++]=cnt;
    for(int i=0;i<m;i++)
    {
        int q;
        scanf("%d",&q);
        printf("%I64d ",res[q]);
    }
    printf("\n");
	return 0;
}