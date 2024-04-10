/*#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, C[201000][5], CC[201000][5];
long long res, D[201000][5], DD[201000][5];
vector<int>E[201000];
void DFS(int a, int pp){
    int i, j;
    C[a][0]++;
    for(i=0;i<E[a].size();i++){
        int x = E[a][i];
        if(x==pp)continue;
        DFS(x,pp);
        for(j=0;j<K;j++){
            C[a][(j+1)%K] += C[x][j];
            D[a][(j+1)%K] += D[x][j];
            if(j==0)D[a][(j+1)%K] += C[x][j];
        }
    }
}
void Make(int a, int *TC, long long *TD){
    int i;
    int T1[5]={0};
    long long T2[5]={0};
    for(i=0;i<K;i++){
        T1[i] = TC[i] - C[a][i];
        T2[i] = TD[i] - D[a][i];
        CC[a][(i+2)%K] += T1[i];
        DD[a][(i+2)%K] += T2[i];
        if(i%K==0)DD[a][(i+2)%K] += T1[i];
        if((i+1)%K==0)DD[a][(i+2)%K] += T1[i];
    }
    CC[a][1%K] += 1;
    DD[a][1%K] += 1;
}
void Do(int a, int pp){
    int i, j, TC[5]={0};
    long long TD[5]={0};
    for(i=0;i<E[a].size();i++){
        int x = E[a][i];
        if(x==pp)continue;
        for(j=0;j<K;j++)TC[j]+=C[x][j], TD[j]+=D[x][j];
    }
    for(i=0;i<E[a].size();i++){
        int x = E[a][i];
        if(x==pp)continue;
        Make(x,TC,TD);
    }
}
int main(){
    int i, j, a, b;
    scanf("%d%d",&n,&K);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    for(i=1;i<=n;i++)for(j=0;j<K;j++)CC[i][j]=C[i][j],DD[i][j]=D[i][j];
    Do(1,0);
}*/
#include<cstdio>
#include<algorithm>
using namespace std;
char p[80];
int D[80][80][80][3];
int A[80],CA,B[80],CB,C[80],CC;
int Calc(int a, int b, int c, int pv){
    int i, cc = 0;
    for(i=1;i<=a;i++)if(pv < A[i])cc++;
    for(i=1;i<=b;i++)if(pv < B[i])cc++;
    for(i=1;i<=c;i++)if(pv < C[i])cc++;
    return cc;
}
int main(){
    int i, j, k, l, n;
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;p[i];i++){
        if(p[i]=='V')A[++CA] = i;
        else if(p[i]=='K')B[++CB] = i;
        else C[++CC] = i;
    }
    for(i=0;i<=CA;i++)for(j=0;j<=CB;j++)for(k=0;k<=CC;k++)for(l=0;l<3;l++)D[i][j][k][l]=1e9;
    D[0][0][0][2] = 0;
    for(i=0;i<=CA;i++){
        for(j=0;j<=CB;j++){
            for(k=0;k<=CC;k++){
                for(l=0;l<3;l++){
                    if(i!=CA){
                        D[i+1][j][k][0] = min(D[i+1][j][k][0], D[i][j][k][l] + Calc(i,j,k,A[i+1]));
                    }
                    if(j!=CB && l){
                        D[i][j+1][k][1] = min(D[i][j+1][k][1], D[i][j][k][l] + Calc(i,j,k,B[j+1]));
                    }
                    if(k!=CC){
                        D[i][j][k+1][2] = min(D[i][j][k+1][2], D[i][j][k][l] + Calc(i,j,k,C[k+1]));
                    }
                }
            }
        }
    }
    int res = 1e9;
    for(i=0;i<3;i++)res = min(res, D[CA][CB][CC][i]);
    printf("%d\n",res);
}