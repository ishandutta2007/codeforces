#include <stdio.h>

bool check(int n){
    int c[10];
    for(int i=0; i<10; i++) c[i]=0;
    while(n>0){
        if(c[n%10]++)return false;
        n/=10;
    }
    return true;
    }
    
    int main(){
    int x;
    scanf("%d",&x);
    while(++x) if(check(x)) return 0&printf("%d\n",x);
    return 0;
    }