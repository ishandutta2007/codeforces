#include<stdio.h>
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    int be = 1, ed = n;
    for(i=1;i<=k;i++){
        if(i%2==1){
            printf("%d ",be);
            be++;
        }
        else{
            printf("%d ",ed);
            ed--;
        }
    }
    if(i%2==0){
        while(be<=ed){
            printf("%d ",be);
            be++;
        }
    }
    else{
        while(ed>=be){
            printf("%d ",ed);
            ed--;
        }
    }
}