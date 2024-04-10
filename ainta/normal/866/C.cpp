#include<cstdio>
#include<algorithm>
#define double long double
using namespace std;
double D[52][5010], P[52];
int n, A[52], B[52], M;
bool Pos(double L){
    int i, j;
    for(i=0;i<=100*n;i++){
        if(i <= M) D[n][i] = 0;
        else D[n][i] = L;
    }
    for(i=n;i>=1;i--){
        for(j=0;j<=100*(i-1);j++){
            D[i-1][j] = min(L, P[i] * (D[i][j+A[i]] + A[i]) + (1.0 - P[i]) * (D[i][j+B[i]] + B[i]));
        }
    }
    return D[0][0] < L;
}
int main(){
    int i;
    scanf("%d%d",&n,&M);
    double b = 0.0, e = 1e15, mid;
    for(i=1;i<=n;i++){
        scanf("%d%d%Lf",&A[i],&B[i],&P[i]);
        P[i]/=100.0;
        b += A[i];
    }
    for(i=0;i<100;i++){
        mid = (b+e)*0.5;
        if(Pos(mid))e=mid;
        else b=mid;
    }
    printf("%.11Lf\n",(b+e)*0.5);
}