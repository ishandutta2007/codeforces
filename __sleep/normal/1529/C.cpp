#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=200005;
int t,n,l[N],r[N];
long long dp[N][2];
vector<int> nxt[N];
void dfs(int x,int fa){
    dp[x][0]=dp[x][1]=0;
    for(auto v:nxt[x]){
        if(v==fa) continue;
        dfs(v,x);
        dp[x][0]+=max(dp[v][0]+abs(l[v]-l[x]),dp[v][1]+abs(r[v]-l[x]));
        dp[x][1]+=max(dp[v][0]+abs(l[v]-r[x]),dp[v][1]+abs(r[v]-r[x]));
    }
}
int main(){
    int u,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",l+i,r+i);
            nxt[i].clear();
        }
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            nxt[u].push_back(v);
            nxt[v].push_back(u);
        }
        dfs(1,0);
        printf("%lld\n",max(dp[1][0],dp[1][1]));
    }
    return 0;
}