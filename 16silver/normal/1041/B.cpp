#include <cstdio>
long long gcd(long long x, long long y){
    long long r=x%y;
    while(r>0){
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main(){
    long long a,b,x,y;
    scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
    long long g=gcd(x,y);
    x=x/g;
    y=y/g;
    printf("%lld",(a/x)>(b/y)?(b/y):(a/x));
}