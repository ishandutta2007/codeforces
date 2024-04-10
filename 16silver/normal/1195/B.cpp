#include <cstdio>

int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long sq;
    for(sq=0;sq*sq!=(8*n+8*k+9);sq++);
    printf("%lld\n",(2*n+3-sq)/2);
}