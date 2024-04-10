#include<cstdio>
#include<algorithm>
#include<cstdio>
long double D[10010][1010];
int n, Q, a;
int main(){
    int i, j;
    scanf("%d",&n);
    D[0][0] = 1.0;
    for(i=0;i<10*n;i++){
        for(j=0;j<=i && j<=n;j++){
            if(D[i][j] < 1e-30)continue;
            D[i+1][j] += D[i][j] * j/n;
            D[i+1][j+1] += D[i][j] * (n-j)/n;
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&a);
        for(i=n;;i++){
            if(D[i][n] >= a/2000.0)break;
        }
        printf("%d\n",i);
    }
}