#include<stdio.h>
#include<algorithm>
using namespace std;
int D[510][510];
int w[510];
int n;
int main(){
    int i, j, b, e, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1-i;j++){
            b = j, e = j+i-1;
            if(b==e){
                D[b][e] = 1;
                continue;
            }
            D[b][e] = n+1;
            if(w[b] == w[e]){
                if(b+1<=e-1)D[b][e] = min(D[b][e], D[b+1][e-1]);
                else D[b][e] = min(D[b][e], 1);
            }
            for(k=b;k<e;k++){
                D[b][e] = min(D[b][e], D[b][k] + D[k+1][e]);
            }
        }
    }
    printf("%d\n",D[1][n]);
}