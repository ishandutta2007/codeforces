#include<stdio.h>
int n;
long long t = 2;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        long long tp = i;
        tp=tp*(i+1);
        printf("%lld\n",tp*(i+1)-(t/i));
        t = 1ll*i*(i+1);
    }
}