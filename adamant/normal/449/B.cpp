#include <bits/stdc++.h>

using namespace std;

#define TASK "test"
#define int long long

const int INF=1e9;

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,int>>> G(n);
    unordered_map<int,map<int,int>> C;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(C[a-1][b-1] && C[a-1][b-1]<c) continue;
        G[a-1].push_back({b-1,c});
        G[b-1].push_back({a-1,c});
        C[a-1][b-1]=C[b-1][a-1]=c;
    }
    vector<vector<pair<int,int>>> Gt(G);
    int ans=0;
    C.clear();
map<int,int> Q;
    for(int i=0;i<k;i++)
    {
        int a=1,b,c;
        cin>>b>>c;
        if(Q[b-1]) ans++;
        if(Q[b-1] && Q[b-1]<c) continue;
        G[a-1].push_back({b-1,c});
        G[b-1].push_back({a-1,c});
        Q[b-1]=c;
    }
    vector<int> dist(n,INF);
    dist[0]=0;
    set<pair<int,int>> que;
    que.insert({0,0});

    while(!que.empty())
    {
        int cur=que.begin()->second;
        que.erase(que.begin());
        for(int i=0;i<G[cur].size();i++)
            if(dist[cur]+G[cur][i].second<dist[G[cur][i].first])
            {
                que.erase(make_pair(dist[G[cur][i].first],G[cur][i].first));
                dist[G[cur][i].first]=dist[cur]+G[cur][i].second;
                que.insert(make_pair(dist[G[cur][i].first],G[cur][i].first));
            }
    }

    vector<pair<int,int>> rails(Q.begin(),Q.end());
    for(int i=0;i<rails.size();i++)
        for(int j=0;j<Gt[rails[i].first].size();j++)
            if(rails[i].second>=Gt[rails[i].first][j].second+dist[Gt[rails[i].first][j].first])
            {
                ans++;
                break;
            }

    cout<<ans<<endl;
 }