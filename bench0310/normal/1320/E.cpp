#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(18,0));
vector<int> tin(N,0);
vector<int> tout(N,0);
int tcnt=1;
vector<array<int,2>> g[N];
vector<int> virus(N,0);
vector<int> speed(N,0);

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    tin[a]=tcnt++;
    for(int i=1;i<18;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
    tout[a]=tcnt-1;
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=17;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=17;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

int dist(int a,int b)
{
    return (depth[a]+depth[b]-2*depth[lca(a,b)]);
}

bool sub(int a,int b)
{
    return (tin[a]<=tin[b]&&tin[b]<=tout[a]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    int qq;
    cin >> qq;
    while(qq--)
    {
        int k,m;
        cin >> k >> m;
        vector<int> req;
        vector<int> viruses(k+1,0);
        for(int i=1;i<=k;i++)
        {
            cin >> viruses[i];
            cin >> speed[i];
            req.push_back(viruses[i]);
        }
        vector<int> cities(m);
        for(int i=0;i<m;i++)
        {
            cin >> cities[i];
            req.push_back(cities[i]);
        }
        sort(req.begin(),req.end(),[&](const int &a,const int &b){return (tin[a]<tin[b]);});
        for(int i=0;i<k+m-1;i++) req.push_back(lca(req[i],req[i+1]));
        sort(req.begin(),req.end(),[&](const int &a,const int &b){return (tin[a]<tin[b]);});
        stack<int> s;
        s.push(req[0]);
        for(int i=1;i<(int)req.size();i++)
        {
            if(req[i]==req[i-1]) continue;
            while(!sub(s.top(),req[i])) s.pop();
            int d=dist(req[i],s.top());
            g[req[i]].push_back({s.top(),d});
            g[s.top()].push_back({req[i],d});
            s.push(req[i]);
        }
        priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>> q; //move,virus,dest,time
        auto getmv=[&](int i,int t)->int
        {
            return ((t+speed[i]-1)/speed[i]);
        };
        for(int i=1;i<=k;i++) q.push({0,i,viruses[i],0});
        while(!q.empty())
        {
            auto [mv,vr,a,t]=q.top();
            q.pop();
            if(virus[a]!=0) continue;
            virus[a]=vr;
            for(auto [to,d]:g[a])
            {
                q.push({getmv(vr,t+d),vr,to,t+d});
            }
        }
        for(int a:cities) cout << virus[a] << " ";
        cout << "\n";
        for(int i=1;i<=k;i++) speed[i]=0;
        for(int a:req)
        {
            virus[a]=0;
            g[a].clear();
        }
    }
    return 0;
}