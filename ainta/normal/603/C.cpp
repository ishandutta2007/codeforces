#include<stdio.h>
int n, K, w[101000], P;
int Gap(int a){
    if(a>=5){
        if(a%2==1)return 0;
        int t = Gap(a/2);
        if(t==0)return 1;
        if(t==1)return 2;
        if(t==2)return 1;
    }
    if(a==1)return 1;
    if(a==2)return 0;
    if(a==3)return 1;
    if(a==4)return 2;
}
int main(){
    int i, j;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    if(K%2==0){
        for(i=1;i<=n;i++){
            if(w[i]==1)P^=1;
            else if(w[i]==2)P^=2;
            else{
                if(w[i]%2==0)P^=1;
            }
        }
        if(P)printf("Kevin\n");
        else printf("Nicky\n");
        return 0;
    }
    for(i=1;i<=n;i++){
        P ^= Gap(w[i]);
    }
        if(P)printf("Kevin\n");
        else printf("Nicky\n");
}