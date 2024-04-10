#include<stdio.h>
int T,n;
int main(){
    scanf("%d",&T);
    while(T--)
        scanf("%d",&n),printf("%d\n",n>>1);
    return 0;
}