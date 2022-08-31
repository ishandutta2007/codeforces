#include<stdio.h>
long long K;
int w[40], cnt, C[42][42], r=4;
int main(){
    int i, j;
    scanf("%lld",&K);
    while(K){
        w[cnt++] = K%3;
        K/=3;
    }
    for(i=0;i<cnt;i++){
        if(i){
            C[i][i+3]|=1;
            C[i+3][i]|=2;
            r+=2;
            if(i!=cnt-1){
                C[i][i+4]|=2;
                C[i+4][i]|=1;
                r+=2;
            }
        }
        if(!w[i]){
            C[i+1][i+3]|=2;
            r++;
        }
        if(w[i]!=2){
            C[i+3][i+1]|=1;
            r++;
        }
    }
    for(i=cnt+1;i<=cnt+2;i++){
        C[cnt+2][i]|=1;
        C[i][cnt+2]|=2;
    }
    printf("%d %d\n%d\n",cnt+3,cnt+3,r);
    for(i=1;i<=cnt+2;i++){
        for(j=1;j<=cnt+2;j++){
            if(C[i][j]&1)printf("%d %d %d %d\n",i,j,i+1,j);
            if(C[i][j]&2)printf("%d %d %d %d\n",i,j,i,j+1);
        }
    }
}