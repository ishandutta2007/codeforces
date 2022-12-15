#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;

int n,m,q,arr[200][200];
int ad[10],bd[10];
vector<pii> adj[200][200];
int cf[200][200],vis[200][200];
vector<vector<int>> cn;
vector<int> cvis;
vector<vector<pii>> con;

char str[1000010];

bool make(int i,int j) {
    if(vis[i][j]==1) {
        cn.push_back(vector<int>(10,0));
        con.push_back(vector<pii>());
        cvis.push_back(0);
        return true;
    }
    vis[i][j]=1;
    for(auto &it:adj[i][j]){
        if(vis[it.fi][it.se]!=2) {
            if(make(it.fi, it.se)) {
                cf[i][j]=sz(cn)-1;
                cn.back()[arr[i][j]]=1;
                con.back().push_back(pii(i,j));
                vis[i][j]=2;
                return true;
            }
        }
    }
    vis[i][j]=2;
    return false;
}

bool dfs(int i,int j,int k) {
    if(cf[i][j]!=-1) {
        for(;k>=0;k--) {
           if(!cn[cf[i][j]][str[k]]) break;
        }
        if(k<0) return true;
        for(auto &cur:con[cf[i][j]]) for(auto &it:adj[cur.fi][cur.se]) if(cf[it.fi][it.se]==-1) {
            if(dfs(it.fi,it.se,k)) return true;
        }
    } else {
        if(str[k] == arr[i][j]) k--;
        if(k<0) return true;
        for(auto &it:adj[i][j]) if(dfs(it.fi,it.se,k)) return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%1d",&arr[i][j]);
    for(int i=0;i<10;i++) scanf("%d%d",ad+i,bd+i);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) {
        int a=ad[arr[i][j]],b=bd[arr[i][j]];
        if(i+a>=0 && j+b>=0 && i+a<n && j+b<m) {
            adj[i+a][j+b].push_back(pii(i,j));
        } else adj[i][j].push_back(pii(i,j));
    }
    memset(cf,-1,sizeof(cf));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(!vis[i][j]) {
        make(i,j);
    }
    while(q--) {
        scanf("%s",str);
        int l=strlen(str);
        for(int i=0;i<l;i++) str[i]-='0';
        
        int f=0;
        fill(cvis.begin(),cvis.end(),0);
        for(int i=0;i<n && !f;i++) for(int j=0;j<m;j++) if(cf[i][j]!=-1 && !cvis[cf[i][j]]) {
            cvis[cf[i][j]]=1;
            if(dfs(i,j,l-1)) {
                f=1;
                break;
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}