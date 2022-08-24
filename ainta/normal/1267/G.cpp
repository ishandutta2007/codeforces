#include<cstdio>
#include<algorithm>
using namespace std;
int n, X, sum, w[110];
double D[110][10100];
int main(){
    int i, a, j, k;
    scanf("%d%d",&n,&X);
    D[0][0]=1.0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        a=w[i];
        for(j=i-1;j>=0;j--){
            for(k=sum;k>=0;k--){
                D[j+1][k+a] += D[j][k] * (j+1)/(n-j);
            }
        }
        sum+=a;
    }
    double res=0.0;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(2*j >= (n+i)*X){
                res += D[i][j]*(n+i)*X/i/2;
            }
            else res+=D[i][j]*j/i;
        }
    }
    printf("%.10f\n",res);
}