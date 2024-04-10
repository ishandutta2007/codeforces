#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 99999999
using namespace std;
vector<int>E[3010];
int D[3010][3010], n, m, Q[3010], Res, r1,r2,r3,r4;
int L1[3010][3], L2[3010][3];
void BFS(int st){
    int i, h = 0, t = 0, x;
    for(i=1;i<=n;i++)D[st][i] = INF;
    Q[++t] = st, D[st][st] = 0;
    while(h<t){
        x = Q[++h];
        for(i=0;i<E[x].size();i++){
            if(D[st][E[x][i]] == INF){
                D[st][E[x][i]] = D[st][x] + 1;
                Q[++t] = E[x][i];
            }
        }
    }
}
int main(){
    int i, a, b, j, k, l;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
    }
    for(i=1;i<=n;i++){
        BFS(i);
    }
    for(i=1;i<=n;i++){
        int M1 = -INF, M2 = -INF, M3 = -INF, x1=0, x2=0, x3=0;
        for(j=1;j<=n;j++){
            if(D[j][i] != INF && i!=j){
                if(M1<D[j][i]){
                    M3=M2;x3=x2;
                    M2=M1;x2=x1;
                    M1=D[j][i];x1=j;
                }
                else if(M2 < D[j][i]){
                    M3=M2;x3=x2;
                    M2=D[j][i];x2=j;
                }
                else{
                    M3 = D[j][i], x3 = j;
                }
            }
        }
        L1[i][0] = x1, L1[i][1]=x2,L1[i][2]=x3;
        M1 = -INF, M2 = -INF, M3 = -INF, x1=0, x2=0, x3=0;
        for(j=1;j<=n;j++){
            if(D[i][j] != INF && i!=j){
                if(M1<D[i][j]){
                    M3=M2;x3=x2;
                    M2=M1;x2=x1;
                    M1=D[i][j];x1=j;
                }
                else if(M2 < D[i][j]){
                    M3=M2;x3=x2;
                    M2=D[i][j];x2=j;
                }
                else{
                    M3 = D[i][j], x3 = j;
                }
            }
        }
        L2[i][0] = x1, L2[i][1]=x2,L2[i][2]=x3;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(D[i][j]==INF||i==j)continue;
            for(k=0;k<3;k++){
                a = L1[i][k];
                for(l=0;l<3;l++){
                    b = L2[j][l];
                    if(!a||!b)continue;
                    if(a==j||b==i||a==b)continue;
                    if(Res <D[a][i]+D[i][j]+D[j][b]){
                        Res = D[a][i]+D[i][j]+D[j][b];
                        r1=a,r2=i,r3=j,r4=b;
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n",r1,r2,r3,r4);
}