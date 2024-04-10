//Long tail hedgehog
#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#define _f(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
using namespace std;


int main() {

    int n,m;
    cin >> n >> m;

    vector<int> G[n+1];
    map<int,int> dp;

    _f(i,1,n+1)
        dp[i]=1;

    _f(i,0,m) {
        int u,v;
        scanf("%d%d", &u,&v);
//        cin >> u >> v;
//        deg[u]++, deg[v]++;
        G[u].pb(v);
        G[v].pb(u);
    }

    _f(i,1,n+1) {
        _f(j,0,G[i].size()) {
            int x = G[i][j];
            dp[x] = (x>i)?max(dp[x],dp[i]+1):dp[x];
        }
    }//O(n+m)
    long long int ans = 1;
    _f(i,1,n+1){
        long long int yo = G[i].size()*(long long)dp[i];
        ans = max(ans,yo);
    }
    cout << ans;

    return 0;
}