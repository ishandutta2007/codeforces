#include<stdio.h>
int Get(long long n, long long x, long long t){
    if(x == t)return n%2;
    if(x > t)return Get(n/2, x-t, t/2);
    return Get(n/2, x, t/2);
}
int main(){
    long long n, l, r;
    scanf("%lld%lld%lld",&n,&l,&r);
    if(n==0){
        printf("0\n");
        return 0;
    }
    long long i;
    int s = 0;
    for(i=0;i<60;i++){
        if((1ll<<i) > n)break;
    }
    long long g = 1ll << (i-1);
    for(i=l;i<=r;i++){
        s += Get(n, i, g);
    }
    printf("%d\n",s);
}