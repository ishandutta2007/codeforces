#include<stdio.h>
int main(){
    int a,b,c,d,e,f, L;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    L = a+b+c;
    printf("%d\n",L*L - a*a - c*c - e*e);
}