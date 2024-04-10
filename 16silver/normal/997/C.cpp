#include <cstdio>
#include <algorithm>
#define P 998244353
using namespace std;
long long powm(long long x, long long y){
    if(x<0) x=x+P;
    if(y == 0LL) return 1LL;
    if(y == 1LL) return x;
    long long h = powm(x,y/2LL);
    if(y % 2 == 1){
        return ((h*h)%P*x)%P;
    }
    else return (h*h)%P;
}
long long fac[1000001];
long long facinv[1000001];
long long p3[1000001];
int main(){
    int n,i;
    long long ans, no3, bino;
    scanf("%d",&n);
    fac[0] = 1LL;
    p3[0] = 1LL;
    facinv[0] = 1LL;
    for(i=1;i<=n;i++){
        fac[i] = (fac[i-1]*i)%P;
        p3[i] = (p3[i-1]*3)%P;
        facinv[i] = powm(fac[i],P-2);
    }
    no3 = powm(3LL,n);
    ans = (2LL*(P+powm(no3,n)-powm(no3-3LL,n)))%P;
    ans = (ans + P + 3LL*(powm(no3-1LL, n) - powm(no3,n)))%P;
    for(i=1;i<=n;i++){
        bino = ((fac[n] * facinv[i])%P * facinv[n-i])%P;
        if(i%2 == 1){
            ans = (ans + (bino * powm(p3[n-i]-1LL,n))%P*3LL)%P;
        }
        else{
            ans = (ans + P * 3LL - (bino * powm(p3[n-i]-1LL,n))%P*3LL)%P;
        }
    }
    ans = ans % P;
    printf("%lld",ans);
}