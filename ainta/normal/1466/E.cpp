#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, C[60];
long long w[501000], Mod = 1000000007, po[62];
void Solve(){
    int i, j, k;
    po[0]=1;
    for(i=1;i<=60;i++)po[i]=po[i-1]*2%Mod;
    scanf("%d",&n);
    for(i=0;i<60;i++)C[i]=0;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
        for(j=0;j<60;j++){
            C[j] += ((w[i]>>j)&1);
        }
    }
    long long res=0;
    for(i=1;i<=n;i++){
        long long s=0;
        for(j=0;j<60;j++){
            if((w[i]>>j)&1){
                s=(s+po[j] *C[j])%Mod;
            }
        }
        for(j=0;j<60;j++){
            if((w[i]>>j)&1){
                res = (res + s*po[j]%Mod*n)%Mod;
            }
            else{
                res = (res + s*po[j]%Mod*C[j])%Mod;
            }
        }
    }
    printf("%lld\n",res);
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}