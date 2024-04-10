#include<cstdio>
#include<algorithm>
using namespace std;
double D[64][64], P[64][64], PP[64][64];
int n;
int main(){
    int i, j, k, l;
    scanf("%d",&n);
    for(i=0;i<(1<<n);i++){
        for(j=0;j<(1<<n);j++){
            scanf("%lf",&P[i][j]);
            P[i][j] *= 0.01;
        }
    }
    for(i=1;i<=n;i++){
        int b = (1<<(n-i)), t;
        for(j=0, t=b;j<(1<<n);j+=(1<<i), t++){
            if(i == 1){
                PP[t][j] = D[t][j] = P[j][j+1];
                PP[t][j+1] = D[t][j+1] = P[j+1][j];
                continue;
            }
            for(k=j;k<j+(1<<(i-1));k++){
                for(l=j+(1<<(i-1));l<j+(1<<i);l++){
                    PP[t][k] += PP[t*2][k] * PP[t*2+1][l] * P[k][l];
                    PP[t][l] += PP[t*2][k] * PP[t*2+1][l] * P[l][k];
                    double tp = PP[t*2][k] * PP[t*2+1][l];
                }
            }
            for(k=j;k<j+(1<<(i-1));k++){
                for(l=j+(1<<(i-1));l<j+(1<<i);l++){
                    double tp = PP[t*2][k] * PP[t*2+1][l];
                    D[t][k] = max(D[t][k], D[t*2][k] + D[t*2+1][l] + PP[t][k] * (1<<(i-1)));
                    D[t][l] = max(D[t][l], D[t*2][k] + D[t*2+1][l] + PP[t][l] * (1<<(i-1)));
                }
            }
        }
    }
    double res = 0.0;
    for(i=0;i<(1<<n);i++)res=max(res,D[1][i]);
    printf("%.10f\n",res);
}