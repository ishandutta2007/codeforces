#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 2010
using namespace std;
struct vtx{
    long long d;
    int u;
    vtx(){}
    vtx(long long _d,int _u):d(_d),u(_u){}
    bool operator<(const vtx& r)const{return d>r.d;}
};
long long dis[2][N];
int n;
int p[N],id[2][N];
int nxt[2][N][N];
long long dp[2][N][N];
bool chk[2][N][N];
int last[2][N][N];
bool del[N];
vector<int> g[N],w[N];
template<int k>
bool cmp(int i,int j){
    return dis[k][i]<dis[k][j];
}
long long solve(int i,int j,int k){
    if(k==n) return 0;
    if(chk[i][j][k]) return dp[i][j][k];
    chk[i][j][k]=true;
    dp[i][j][k]=solve(i,j,k+1)+(last[i][j][k]?p[id[i][k]]:0);
    if(last[i][j][k]==3) dp[i][j][k]=max(dp[i][j][k],p[id[i][k]]-solve(i^1,k+1,j));
    return dp[i][j][k];
}
int main(){
    int m,s[2];
    scanf("%d%d",&n,&m);
    priority_queue<vtx> pq;
    scanf("%d%d",s,s+1);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x].push_back(y);
        g[y].push_back(x);
        w[x].push_back(z);
        w[y].push_back(z);
    }
    for(int i=0;i<2;i++){
        dis[i][s[i]]=0;
        pq.push(vtx(0,s[i]));
        while(!pq.empty()){
            int u=pq.top().u;
            long long d=pq.top().d;
            pq.pop();
            if(dis[i][u]!=d){
                continue;
            }
            for(int j=0;j<g[u].size();j++){
                int v=g[u][j];
                if(dis[i][u]+w[u][j]<dis[i][v]){
                    dis[i][v]=dis[i][u]+w[u][j];
                    pq.push(vtx(dis[i][v],v));
                }
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            id[i][j]=j+1;
        }
    }
    sort(id[0],id[0]+n,cmp<0>);
    sort(id[1],id[1]+n,cmp<1>);
    for(int i=0;i<2;i++){
        memset(del,0,sizeof(del));
        for(int j=0;j<=n;j++){
            for(int k=n-1,pd=-1;k>=0;k--){
                if(!del[id[i][k]]){
                    last[i][j][k]|=1;
                    if(dis[i][id[i][k]]!=pd){
                        last[i][j][k]|=2;
                        pd=dis[i][id[i][k]];
                    }
                }
            }
            if(j<n) del[id[i^1][j]]=true;
        }
    }
    long long ans=solve(0,0,0);
    if(ans>0) puts("Break a heart");
    else if(ans==0) puts("Flowers");
    else puts("Cry");
    return 0;
}