#include<stdio.h>
#include<algorithm>
using namespace std;
int D[510][510], n, w[510], K, cnt;
int main(){
    int i,j,k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    D[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=K-w[i];j>=0;j--){
            for(k=0;k<=j;k++){
                D[j+w[i]][k+w[i]] |= D[j][k];
                D[j+w[i]][k] |= D[j][k];
            }
        }
    }
    for(i=0;i<=K;i++)if(D[K][i])cnt++;
    printf("%d\n",cnt);
    for(i=0;i<=K;i++)if(D[K][i])printf("%d ",i);
}