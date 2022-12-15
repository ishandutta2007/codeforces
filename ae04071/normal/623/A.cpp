#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,m,adj[501][501],chk[501];
pii dfs(int cur,int t) {
    chk[cur]=t;
    
    pii ret(1,0);
    for(int i=1;i<=n;i++) if(adj[cur][i]){
        if(!chk[i]) {
            pii val = dfs(i,t);
            ret.first += val.first;
            ret.second += val.second;
            ret.second++;
        } else if(chk[i]==t) ret.second++;
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++) {
        scanf("%d%d",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }

    for(int i=1;i<=n;i++) {
        int cnt=0;
        for(int j=1;j<=n;j++) cnt+=adj[i][j];
        if(cnt==n-1) chk[i]=1;
    }

    int f=2,t=2;
    for(int i=1;i<=n;i++) if(!chk[i]) {
        if(!f) {
            puts("No");
            return 0;
        }
        pii val = dfs(i,t);
        if(val.second != val.first*(val.first-1)) {
            puts("No");
            return 0;
        }
        t++;
        f--;
    }
    puts("Yes");
    for(int i=1;i<=n;i++) {
        if(chk[i]==1) printf("b");
        else if(chk[i]==2) printf("a");
        else printf("c");
    }
        
    
    return 0;
}