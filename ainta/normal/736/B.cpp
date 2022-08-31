#include<stdio.h>
int n;
int main(){
    int i;
    scanf("%d",&n);
    for(i=2;i*i<=n;i++){
        if(n%i==0)break;
    }
    if(i*i>n){
        printf("1\n");
        return 0;
    }
    if(n%2==0){
        printf("2\n");
    }
    else{
        n-=2;
        for(i=2;i*i<=n;i++){
            if(n%i==0)break;
        }
        if(i*i>n)printf("2\n");
        else printf("3\n");
    }
}