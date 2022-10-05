#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1e6+123,inf=1e9,mod=1e9+7;
vector<int> g[maxn],gr[maxn],ans;
int n,m;
bool was[maxn],used[maxn];
void dfs(int v){
    if(v>n)
        return;
    if(was[v]){
        dfs(v+1);
        return;
    }
    was[v]=1;
    bool ok=0;
    for(auto to:g[v])
        was[to]=1;
    dfs(v+1);
    for(auto to:gr[v])
        if(used[to])
            ok=1;
    if(!ok){
        used[v]=1;
        ans.pb(v);
    }
}

int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int v,u;
        scanf("%d%d",&v,&u);
        g[v].pb(u);
        gr[u].pb(v);
    }
    dfs(1);
    printf("%d\n",(int)ans.size());
    for( auto x:ans )
        printf("%d ",x);
}