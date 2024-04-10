
#include<stdio.h>
int TC, n, K, S;
int main(){
    int i, a;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d%d",&n,&K);
        S=0;
        for(i=1;i<n;i++){
            scanf("%d",&a);
            S+=a;
        }
        K%=n;
        printf("%d\n",(K+n-S%n + n-1)%n + 1);
    }
}