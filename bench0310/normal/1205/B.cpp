#include <bits/stdc++.h>

using namespace std;

const int inf=1000000;
const int N=128;
set<int> g[N];

int dijkstra(int src,int goal)
{
    vector<int> d(N,inf);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    d[src]=0;
    q.push({0,src});
    while(!q.empty())
    {
        int e=q.top().second;
        int temp=q.top().first;
        q.pop();
        if(d[e]<temp) continue;
        for(int to:g[e])
        {
            if(d[e]+1<d[to])
            {
                d[to]=d[e]+1;
                q.push({d[to],to});
            }
        }
    }
    return d[goal];
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<long long> a(n);
	vector<int> cnt(64,0);
	for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        long long t=a[i];
        int e=0;
        while(t)
        {
            if(t&1) cnt[e]++;
            t/=2;
            e++;
        }
    }
    for(int i=0;i<64;i++)
    {
        if(cnt[i]>=3)
        {
            printf("3\n");
            return 0;
        }
    }
    set<long long> s;
    for(int i=0;i<n;i++) if(a[i]>0) s.insert(a[i]);
    n=s.size();
    vector<long long> v;
    for(long long t:s) v.push_back(t);
    vector<pair<int,int>> edges;
    for(int o=0;o<n;o++)
    {
        for(int i=o+1;i<n;i++)
        {
            if((v[o]&v[i])>0)
            {
                g[o].insert(i);
                g[i].insert(o);
                edges.push_back({o,i});
            }
        }
    }
    int res=inf;
    for(pair<int,int> p:edges)
    {
        g[p.first].erase(p.second);
        g[p.second].erase(p.first);
        res=min(res,dijkstra(p.first,p.second)+1);
        g[p.first].insert(p.second);
        g[p.second].insert(p.first);
    }
    if(res==inf) res=-1;
    printf("%d\n",res);
	return 0;
}