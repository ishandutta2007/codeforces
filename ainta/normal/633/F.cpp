#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[101000];
vector<int>E[101000];
long long D[101000][3], Res;
void DFS(int a, int pp){
    int i, x, j, k, t;
    long long M[3][3]={0};
    int Num[3][3]={0};
    for(i=0;i<E[a].size();i++){
        x = E[a][i];
        if(x==pp)continue;
        DFS(x,a);
        for(j=0;j<3;j++){
            for(k=0;k<3;k++)if(M[j][k]<D[x][j])break;
            if(k==3)continue;
            t = k;
            for(k=2;k>t;k--)M[j][k]=M[j][k-1], Num[j][k]=Num[j][k-1];
            M[j][t] = D[x][j], Num[j][t] = x;
        }
    }
    D[a][0] = M[0][0]+w[a];
    D[a][1] = max(M[0][0]+M[0][1]+w[a],M[1][0]);
    D[a][2] = M[2][0]+w[a];
    if(Num[0][0] == Num[1][0])D[a][2] = max(D[a][2],max(M[0][0]+M[1][1]+w[a],M[0][1]+M[1][0]+w[a]));
    else D[a][2]= max(D[a][2], M[0][0]+M[1][0]+w[a]);
    Res = max(Res, M[1][0]+M[1][1]);
    if(Num[0][0] == Num[2][0])Res = max(Res,max(M[0][0]+M[2][1]+w[a],M[0][1]+M[2][0]+w[a]));
    else Res = max(Res, M[0][0]+M[2][0]+w[a]);
    for(i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            for(k=0;k<3;k++){
                if(Num[0][i]!=Num[1][k] && Num[0][j]!=Num[1][k])Res = max(Res, M[0][i]+M[0][j]+M[1][k]+w[a]);
            }
        }
    }
}
int main(){
    int i, a, b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1,0);
    printf("%lld\n",Res);
}