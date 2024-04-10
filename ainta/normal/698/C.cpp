#include<stdio.h>
#include<algorithm>
using namespace std;
double D[1048576], w[22], Res[22];
bool chk[22];
int n, K, M;
int main(){
    int i, j;
    scanf("%d%d",&n,&K);
    M = n;
    for(i=0;i<n;i++){
        scanf("%lf",&w[i]);
        if(w[i] < 0.001){
            chk[i] = true;
            M--;
        }
    }
    D[0] = 1.0;
    for(i=0;i<(1<<n);i++){
        int c = 0;
        double s = 0.0;
        for(j=0;j<n;j++){
            if((1<<j)&i){
                c++;
            }
            else{
                s+=w[j];
            }
        }
        if(c == min(M,K)){
            for(j=0;j<n;j++){
                if((1<<j)&i) Res[j] += D[i];
            }
        }
        if(s <1e-17)continue;
        for(j=0;j<n;j++){
            if(!((1<<j)&i)){
                D[i|(1<<j)] += D[i] * w[j]/s;
            }
        }
    }
    for(i=0;i<n;i++)printf("%.11f ", Res[i]);
}