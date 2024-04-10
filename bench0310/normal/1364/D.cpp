#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> vis(N,0);
vector<int> c(N,-1);
vector<int> cycle;
vector<int> now;

void dfs(int a)
{
    now.push_back(a);
    vis[a]=1;
    for(int to:v[a])
    {
        if(vis[to]==0)
        {
            c[to]=1-c[a];
            dfs(to);
        }
        else if(vis[to]==1&&now[now.size()-2]!=to&&cycle.empty())
        {
            bool ok=0;
            for(int x:now)
            {
                if(x==to) ok=1;
                if(ok) cycle.push_back(x);
            }
        }
    }
    now.pop_back();
    vis[a]=2;
}

void one(vector<int> res)
{
    cout << "1\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    exit(0);
}

void two(vector<int> res)
{
    cout << "2\n";
    cout << res.size() << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<array<int,2>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edges.push_back({a,b});
    }
    c[1]=0;
    dfs(1);
    if(cycle.empty())
    {
        vector<int> res[2];
        for(int i=1;i<=n;i++) res[c[i]].push_back(i);
        if(res[0].size()<res[1].size()) swap(res[0],res[1]);
        while((int)res[0].size()>(k+1)/2) res[0].pop_back();
        one(res[0]);
    }
    else
    {
        int sz=cycle.size();
        vector<int> d(n+1,-1);
        for(int i=0;i<sz;i++) d[cycle[i]]=i;
        auto len=[&](int a,int b)->int
        {
            return min(abs(d[a]-d[b]),sz-abs(d[a]-d[b]))+1;
        };
        array<int,2> x={-1,-1};
        for(auto [a,b]:edges)
        {
            if(d[a]==-1||d[b]==-1) continue;
            if(len(a,b)!=2&&(x[0]==-1||len(a,b)<len(x[0],x[1]))) x={a,b};
        }
        if(x[0]!=-1)
        {
            auto [a,b]=x;
            vector<int> aa;
            for(int i=d[a];i!=d[b];i=(i+1)%sz) aa.push_back(cycle[i]);
            aa.push_back(b);
            vector<int> bb;
            for(int i=d[b];i!=d[a];i=(i+1)%sz) bb.push_back(cycle[i]);
            bb.push_back(a);
            if(aa.size()>bb.size()) swap(aa,bb);
            cycle=aa;
        }
        sz=cycle.size();
        if(sz<=k) two(cycle);
        else
        {
            vector<int> res;
            for(int i=0;i<sz-(sz&1);i+=2) res.push_back(cycle[i]);
            while((int)res.size()>(k+1)/2) res.pop_back();
            one(res);
        }
    }
    return 0;
}