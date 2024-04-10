#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define debug 
#define inf (1e6)
#define ll long long
using namespace std;
 
vector<int> L[maxn];

int sz[maxn];
ll sd[maxn];

void dfs(int vx,int p){
    
    sz[vx] = 1;
    
    for(int i=0;i<L[vx].size();i++) if(L[vx][i] != p){
        dfs(L[vx][i],vx);
        sz[vx] += sz[L[vx][i]];
        sd[vx] += sd[L[vx][i]] + sz[L[vx][i]];
    }
    
}

ll mx;

int n;
void dfs2(int vx,ll s,int p=0){
    mx = max(mx,s);
    
    for(int i=0;i<L[vx].size();i++) if(L[vx][i] != p){
        dfs2(L[vx][i], s - sz[L[vx][i]] + (n - sz[L[vx][i]]) , vx);
    }
} 
 
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    dfs(0,0);
    dfs2(0,sd[0]);
    printf("%lld\n",mx+n);
}