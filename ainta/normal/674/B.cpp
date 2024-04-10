#include<stdio.h>
int n, K, a, b, c, d;
int main(){
    int i;
    scanf("%d%d",&n,&K);
    if(K<n+1 || n==4){
        printf("-1\n");
        return 0;
    }
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d %d ",a,c);
    for(i=1;i<=n;i++){
        if(i==a||i==b||i==c||i==d)continue;
        printf("%d ",i);
    }
    printf("%d %d\n",d,b);
    printf("%d %d ",c,a);
    for(i=1;i<=n;i++){
        if(i==a||i==b||i==c||i==d)continue;
        printf("%d ",i);
    }
    printf("%d %d\n",b,d);
}