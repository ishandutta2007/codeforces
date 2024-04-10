#include<stdio.h>
long long D[110], n;
int main(){
    int i;
    D[0] = 1;
    D[1] = 2;
    for(i=1;;i++){
        D[i+1] = D[i] + D[i-1];
        if(D[i+1] > 1e18)break;
    }
    scanf("%lld",&n);
    for(i=i;i>=0;i--){
        if(D[i] <= n)break;
    }
    printf("%d\n",i);
}