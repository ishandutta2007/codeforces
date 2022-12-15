#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;

int n;
vector<pii> adj[1001];

vector<pair<int,pii>> ans;

int get(int cur,int p,int s) {
    int f=0,v=0;
    for(auto &it:adj[cur]) {
        if(it.se==p) it.fi -= s;
        else if(!f) {
            it.fi -= s;
            v = get(it.se, cur, s);
            f = 1;
        }
    }
    if(!v) v=cur;
    return v;
}
void dfs(int cur,int p) {
    for(auto &it:adj[cur]) if(it.se!=p) {
        int s=it.fi,r[3],rc=1;
        r[0] = get(it.se, cur, s);
        
        for(auto &jt:adj[cur]) if(it!=jt) {
            r[rc++]=get(jt.se, cur, 0);
            if(rc==3) break;
        }
        ans.push_back({s/2, pii(r[0],r[1])});
        ans.push_back({s/2, pii(r[0],r[2])});
        ans.push_back({-s/2, pii(r[1],r[2])});
    }

    for(auto &it:adj[cur]) if(it.se!=p) {
        dfs(it.se, cur);
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1,u,v,w;i<n;i++) {
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    if(n==2) {
        printf("YES\n1\n%d %d %d\n",1, 2, adj[1][0].fi);
        return 0;
    }

    int root=1;
    for(int i=1;i<=n;i++) {
        if((int)adj[i].size()==2) {
            puts("NO");
            return 0;
        } else if((int)adj[i].size()>2) {
            root=i;
        }
    }

    dfs(root, 0);
    puts("YES");
    printf("%lu\n",ans.size());
    for(auto &v:ans) printf("%d %d %d\n",v.se.fi,v.se.se,v.fi);
    
    return 0;
}