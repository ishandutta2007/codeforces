#include<stdio.h>
#include<algorithm>
using namespace std;
int D[65536][121];
int n, R[65536], B[65536], S1, S2, Res;
struct A{
    int col, x, y;
}w[20];
int main(){
    int i, j, k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char pp[3];
        scanf("%s",pp);
        scanf("%d%d",&w[i].x,&w[i].y);
        S1 += w[i].x, S2 += w[i].y;
        if(pp[0] == 'R') w[i].col = 1;
        else w[i].col = 2;
    }
    for(i=0;i<(1<<n);i++){
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                if(w[j].col == 1)R[i]++;
                else B[i]++;
            }
        }
    }
    for(i=0;i<(1<<n);i++)for(j=0;j<=120;j++)D[i][j] = -1;
    D[0][0] = 0;
    for(i=0;i<(1<<n);i++){
        int rr = R[i], bb = B[i];
        for(j=0;j<=120;j++){
            if(D[i][j]==-1)continue;
            for(k=0;k<n;k++){
                if((1<<k)&i)continue;
                D[i|(1<<k)][j + min(rr,w[k].x)] = max(D[i|(1<<k)][j + min(rr,w[k].x)], D[i][j] + min(bb,w[k].y));
            }
        }
    }
    Res = max(S1, S2);
    for(i=0;i<=120;i++){
        int t = D[(1<<n)-1][i];
        if(t==-1)continue;
        Res = min(Res, max(S1-i,S2-t));
    }
    printf("%d\n",Res + n);
}