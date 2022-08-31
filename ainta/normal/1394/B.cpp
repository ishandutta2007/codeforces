#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
#define N_ 201000
#define pii pair<int,int>
using namespace std;
vector<pii>E[N_];
int n, K, m;
vector<int>G[10];
int CC[201000], chk[10][10], res=0;
int Bad[10][10][10][10], w[10];
bitset<201000> U[10][10];
void DFS(int pv){
    int i, j;
    if(pv==K+1){
        res++;
        return;
    }
    for(i=1;i<=pv;i++){
        if(chk[pv][i])continue;
        int ck=0;
        for(j=1;j<pv;j++){
            if(Bad[j][w[j]][pv][i]){
                ck=1;
                break;
            }
        }
        if(ck)continue;
        w[pv]=i;
        DFS(pv+1);
    }
}
int main(){
    int i, j, k, l;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=m;i++){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        E[a].push_back({c,b});
    }
    for(i=1;i<=n;i++){
        sort(E[i].begin(),E[i].end());
    }
    for(i=1;i<=n;i++)G[E[i].size()].push_back(i);
    for(i=1;i<=K;i++){
        for(j=1;j<=i;j++){
            U[i][j].reset();
            for(k=1;k<=n;k++)CC[k]=0;
            for(auto &x : G[i]){
                int y = E[x][j-1].second;
                CC[y]++;
                if(CC[y]==2)chk[i][j]=1;
                U[i][j][y]=1;
                //printf("%d %d %d\n",i,j,y);
            }
        }
    }
    for(i=1;i<=K;i++){
        for(j=1;j<=i;j++){
            for(k=i;k<=K;k++){
                for(l=1;l<=k;l++){
                    if((U[i][j]&U[k][l]).count()){
                        Bad[i][j][k][l]=Bad[k][l][i][j]=1;
                    }
                }
            }
        }
    }
    DFS(1);
    printf("%d\n",res);
}