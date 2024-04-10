#include <bits/stdc++.h>

using namespace std;

const int N=200000;

struct edge
{
    int u,v;
    long long w;
    bool operator<(const edge & a){return w<a.w;}
};

vector<edge> v;
vector<int> f(N+5);

int findset(int a)
{
	if(a==f[a]) return a;
	return f[a]=findset(f[a]);
}

long long kruskal(vector<edge> & res)
{
	for(int i=0;i<=N;i++) f[i]=i;
    sort(v.begin(),v.end());
    long long mst=0;
    for(int i=0;i<(int)v.size();i++)
    {
        edge e=v[i];
        if(findset(e.u)!=findset(e.v))
        {
            f[findset(e.u)]=findset(e.v);
            res.push_back(e);
            mst+=e.w;
        }
    }
    return mst;
}

int main()
{
    ios::sync_with_stdio(false);
    long long n,m;
    cin >> n >> m;
    long long a[n],b=1000000000000000;
    int id;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]<b)
        {
            b=a[i];
            id=i;
        }
    }
    for(int i=0;i<m;i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        v.push_back(e);
    }
    for(int i=1;i<=n;i++)
    {
        edge e;
        e.u=id+1;
        e.v=i;
        e.w=a[id]+a[i-1];
        v.push_back(e);
    }
    vector<edge> temp;
    cout << kruskal(temp) << endl;
    return 0;
}