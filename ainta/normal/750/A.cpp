#include<stdio.h>
int n, a, s;
int main(){
    int i;
    scanf("%d%d",&n,&a);
    s = a;
    for(i=1;i<=n;i++){
        s += 5*i;
        if(s>240)break;
    }
    printf("%d\n",i-1);
}