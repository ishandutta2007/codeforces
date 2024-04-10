#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

vector<bool> used;

void dfs(int x,vector<vector<int>>&G,vector<int>&res)
{
    used[x]=1;
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i]]) dfs(G[x][i],G,res);
    res.push_back(x);
}

main()
 {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b;
    cin>>n;
    vector<vector<int>> G(n),Gt(n);
    vector<int> cost(n),top_sort,comp;
    for(int i=0;i<n;i++)
        cin>>cost[i];

    cin>>m;
    for(int i=0;i<m;i++)
        cin>>a>>b,
        G[a-1].push_back(b-1),
        Gt[b-1].push_back(a-1);

    used.assign(n,0);
    for(int i=0;i<n;i++)
        if(!used[i])dfs(i,G,top_sort);

    used.assign(n,0);
    long long s1=0,s2=1;
    for(int i=n-1;i>=0;i--)
        if(!used[top_sort[i]])
        {
            comp.clear();
            dfs(top_sort[i],Gt,comp);
            int mi=1e9,c=0;
            for(int i=0;i<comp.size();i++)
                if(cost[comp[i]]==mi)c++;
                else if(cost[comp[i]]<mi)mi=cost[comp[i]],c=1;
            s1+=mi;
            s2=(s2*c)%MOD;
        }
    cout<<s1<<' '<<s2<<endl;
}