#include<bits/stdc++.h>
using namespace std;

int n,A,B;
vector<int> adj[200001];
int dp[200001][2];

int DP(int cur,int p,int d) {
    int &ret=dp[cur][d];
    if(ret!=-1) return ret;

    int mx[2]={0,0};
    ret=0;
    for(auto &it:adj[cur]) if(it!=p) {
        int a=DP(it,cur,0)+1,b=DP(it,cur,1);
        ret += a;
        if(mx[0] > b-a) {
            mx[1]=mx[0]; mx[0]=b-a;
        } else if(mx[1] > b-a) {
            mx[1]=b-a;
        }
    }
    ret += mx[0];
    if(d==0) ret += mx[1];
    return ret;
}
int main() {
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(A<B) {
        memset(dp,-1,sizeof(dp));
        int t=DP(1,0,0);
        printf("%lld\n",1ll*(n-1-t)*A + 1ll*t*B);
    } else {
        for(int i=1;i<=n;i++) if((int)adj[i].size()==n-1) {
            printf("%lld\n",1ll*(n-2)*B+A);
            return 0;
        }
        printf("%lld\n",1ll*(n-1)*B);
    }

    return 0;
}