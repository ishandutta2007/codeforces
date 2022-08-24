#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, Dep[110], H[110];
long long D[110][22][110], TP[110][22][110], Mod = 1000000007, Res;
vector<int>E[110];
void DFS(int a, int pp){
    int i, x, cc = 0, j, k, jj, kk;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x != pp){
            Dep[x] = Dep[a] + 1;
            DFS(x, a);
            H[a] = max(H[a], H[x] + 1);
            cc++;
        }
    }
    if(!cc){
        D[a][0][1] = 1;
        if(K)D[a][1][0] = 1;
        return;
    }
    for(i=0;i<=cc;i++)for(j=0;j<=K;j++)for(k=0;k<=H[a]+1;k++)TP[i][j][k]=0;
    TP[0][0][0] = 1;
    cc = 0;
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        cc++;
        for(jj=0;jj<=K;jj++){
            for(kk=0;kk<=H[a]+1;kk++){
                if(!TP[cc-1][jj][kk])continue;
                long long d = TP[cc-1][jj][kk];
                for(j=0;j<=K;j++){
                    for(k=0;k<=H[x]+1;k++){
                        if(!D[x][j][k])continue;
                        long long d2 = D[x][j][k]*d%Mod;
                        int hh = kk;
                        if(!hh || (k && hh > k))hh = k;
                        if(j==0){
                            if(k && jj + k <= K) TP[cc][0][hh] = (TP[cc][0][hh] + d2)%Mod;
                            else TP[cc][jj][hh] = (TP[cc][jj][hh] + d2)%Mod;
                        }
                        else if(k==0){
                            if(kk && j + kk <= K) TP[cc][jj][hh] = (TP[cc][jj][hh] + d2)%Mod;
                            else TP[cc][max(jj,j)][hh] = (TP[cc][max(jj,j)][hh] + d2)%Mod;
                        }
                        else{
                            int pp = 0;
                            if(jj && (!k || jj+k > K)) pp = jj;
                            if(j && (!kk || j+kk > K)) pp = max(pp,j);
                            TP[cc][pp][hh] = (TP[cc][pp][hh] + d2)%Mod;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<=K;i++){
        for(j=0;j<=H[a]+1;j++){
            D[a][0][1] = (D[a][0][1] + TP[cc][i][j])%Mod;
            if(i==K)continue;
            int tj = j+1;
            if(j==0) tj = 0;
            if(i==0 && (tj && tj <= K+1)){
                D[a][0][tj] = (D[a][0][tj] + TP[cc][i][j])%Mod;
            }
            else D[a][i+1][tj] = (D[a][i+1][tj] + TP[cc][i][j])%Mod;
        }
    }
}
int main(){
    int i, a, b;
    scanf("%d%d",&n,&K);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    for(i=0;i<=n;i++){
        Res = (Res + D[1][0][i])%Mod;
    }
    printf("%lld\n",Res);
}