#include<stdio.h>
int n, H, L;
int main(){
    int i;
    scanf("%d%d%d",&n,&L,&H);
    if(H*2<L || (L==1 && n>=3)){
        printf("-1\n");
        return 0;
    }
    if(H == 1){
        for(i=2;i<=n;i++)printf("%d %d\n",1,i);
        return 0;
    }
    for(i=2;i<=H+1;i++){
        printf("%d %d\n",i-1,i);
    }
    if(H<L){
        printf("%d %d\n",1,H+2);
        for(i=H+2;i<=L;i++){
            printf("%d %d\n",i,i+1);
        }
    }
    for(i=L+2;i<=n;i++)printf("%d %d\n",2,i);
}