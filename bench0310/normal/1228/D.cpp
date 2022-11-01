#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> d(n+1,0);
    set<pair<int,int>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b]++;
        edges.insert({a,b});
    }
    vector<int> v(n+1,-1);
    bool ok=1;
    for(int o=1;o<=3;o++)
    {
        int t=-1;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==-1)
            {
                t=i;
                v[i]=o;
                break;
            }
        }
        if(t==-1) break;
        for(int i=1;i<=n;i++)
        {
            if(i==t) continue;
            if(edges.find({min(t,i),max(t,i)})==edges.end())
            {
                if(v[i]!=-1||d[i]!=d[t]) ok=0;
                v[i]=o;
            }
        }
    }
    vector<int> cnt(4,0);
    for(int i=1;i<=n;i++)
    {
        if(v[i]==-1) ok=0;
        else cnt[v[i]]++;
    }
    if(cnt[1]==0||cnt[2]==0||cnt[3]==0) ok=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==-1) continue;
        if(d[i]!=(n-cnt[v[i]])) ok=0;
    }
    for(pair<int,int> e:edges) if(v[e.first]==v[e.second]) ok=0;
    if(ok) for(int i=1;i<=n;i++) printf("%d%c",v[i]," \n"[i==n]);
    else printf("-1\n");
    return 0;
}