#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

#define int long long

void fail()
{
    cout<<"NO"<<endl;
    exit(0);
}

void dfs(int k,vector<int> &used,vector<vector<int>> &G,vector<vector<int>> &x,int t,int st)
{
    used[k]=1;
    if(x[k][st]!=t) fail();
    for(auto it:G[k])
        if(!used[it])
            dfs(it,used,G,x,t+x[k][it],st);
}

main()
{
#ifndef ONLINE_JUDGE
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> x(n,vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>x[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(x[i][j]!=x[j][i]) fail();
                                              else if(i!=j && x[i][j]<=0) fail();
    for(int i=0;i<n;i++) if(x[i][i]) fail();
    int anc[n];
    memset(anc,-1,sizeof(anc));
    for(int i=1;i<n;i++)
    {
        vector<int> path;
        for(int j=0;j<n;j++) if(x[i][0]==x[i][j]+x[j][0]) path.push_back(j);
        sort(path.begin(),path.end(),[&](int a,int b){return x[0][a]<x[0][b];});
        for(int j=1;j<path.size();j++) if(x[i][path[j-1]]<x[i][path[j]]) fail();
        for(int j=1;j<path.size();j++)
            if(anc[path[j]]!=path[j-1] && anc[path[j]]!=-1) fail();
            else if(x[path[j]][0]!=x[path[j-1]][0]+x[path[j]][path[j-1]]) fail();
            else anc[path[j]]=path[j-1];
    }
    vector<vector<int>> G(n);
    for(int i=1;i<n;i++)
    {
        if(anc[i]==-1) fail();
        G[i].push_back(anc[i]);
        G[anc[i]].push_back(i);
    }
    vector<int> used;
    for(int i=0;i<n;i++)
    {
        used.assign(n,0);
        dfs(i,used,G,x,0,i);
    }
    cout<<"YES"<<endl;
}