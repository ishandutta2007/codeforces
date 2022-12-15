#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,m,gn[100001],vis[100001];
vector<int> adj[100001];
long long cnt[4],sz[4];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int t=1;t<=2;t++) {
        int f=0;
        fill(vis,vis+n+1,0);
        for(int i=1;i<=n;i++) if(!gn[i]) {
            for(auto &it:adj[i]) vis[it] = 1;
            for(int j=1;j<=n;j++) if(!vis[j]) {
                if(gn[j]) {
                    puts("-1");
                    return 0;
                }
                gn[j] = t;
            }
            f=1;
            break;
        }
        if(!f) {
            puts("-1");
            return 0;
        }
    }
    int f=0;
    for(int i=1;i<=n;i++) if(!gn[i]) f=1,gn[i] = 3;
    if(!f) {
        puts("-1");
        return 0;
    }
    for(int i=1;i<=n;i++) for(auto &it:adj[i]) if(gn[it]==gn[i]) {
        puts("-1");
        return 0;
    } else cnt[gn[it]]++;
    for(int i=1;i<=n;i++) sz[gn[i]]++;
    for(int i=1;i<=3;i++) {
        int n1=i%3+1, n2=(i+1)%3+1;
        if(cnt[i] != sz[i] * (sz[n1] + sz[n2])) {
            puts("-1");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",gn[i]);
    
    return 0;
}