#include<cstdio>
#include<algorithm>
using namespace std;
long long n, K, phi, Mod = 1000000007;
int main(){
    int i;
    scanf("%lld%lld",&n,&K);
    for(int tt = 1; tt <= K && n != 1; tt += 2){
        phi = n;
        for(i=2;1ll*i*i<=n;i++){
            if(n%i==0){
                phi = phi / i * (i-1);
                while(n%i==0){
                    n/=i;
                }
            }
        }
        if(n!=1){
            phi = phi / n * (n-1);
        }
        n = phi;
    }
    printf("%lld\n",n% Mod);
}