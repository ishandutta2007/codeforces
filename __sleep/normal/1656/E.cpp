#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=100005;
vector<int> nxt[N];
int n,val[N];
bool dfs(int u,int fa,int sum,int fasum){
    val[u]=sum+(1-nxt[u].size())*fasum;
    if(val[u]==0||abs(val[u])>100000) return false;
    for(auto v:nxt[u]){
        if(v==fa) continue;
        if(!dfs(v,u,fasum,(nxt[u].size()-1)*fasum+val[u])) return false;;
    }
    return true;
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) nxt[i].clear();
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }
    for(int x=1;x<=10;x++)
        for(int y=1;y<=10;y++)
            if(dfs(1,-1,x,y)) goto OK;
    exit(1);
    OK:
    for(int i=1;i<=n;i++)
        printf("%d ",val[i]);
    puts("");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}