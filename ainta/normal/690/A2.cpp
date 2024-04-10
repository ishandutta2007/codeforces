
#include<stdio.h>
int main(){
    int i, n;
    scanf("%d",&n);
    if(n%2==1)printf("%d\n",n/2);
    else{
        for(i=30;i>=0;i--)if((1<<i)&n)break;
        n = (n^(1<<i));
        printf("%d\n",n/2);
    }
}