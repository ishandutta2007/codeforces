#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD=1e9+7;

vector<vector<int>> G,DP;
vector<int> clr;

void dfs(int x)
{
    int n=G[x].size();
    if(!n)
    {
        DP[x][clr[x]]=1;
        return;
    }
    for(int i=0;i<n;i++) dfs(G[x][i]);
    vector<int> pr(n+2,1),sf(n+2,1);
    for(int i=0;i<n;i++)
        pr[i+1]=pr[i]*(DP[G[x][i]][0]+DP[G[x][i]][1])%MOD,
        sf[n-i]=sf[n-i+1]*(DP[G[x][n-i-1]][0]+DP[G[x][n-i-1]][1])%MOD;
    DP[x][clr[x]]=pr[n];
    if(!clr[x]) for(int i=0;i<n;i++) DP[x][1]=(DP[x][1]+pr[i]*sf[i+2]%MOD*DP[G[x][i]][1])%MOD;
}

main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    G.resize(n);
    clr.resize(n);
    DP.assign(n,vector<int>(2));
    for(int i=1;i<n;i++)
    {
        int p;
        cin>>p;
        G[p].push_back(i);
    }
    for(int i=0;i<n;i++) cin>>clr[i];
    dfs(0);
    cout<<DP[0][1]<<endl;
}