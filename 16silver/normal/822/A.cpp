#include <stdio.h>
int main(){
    int A,B,m,r=1,i;
    scanf("%d %d",&A,&B);
    m=(A<B?A:B);
    for(i=1;i<=m;i++) r*=i;
    printf("%d",r);
}