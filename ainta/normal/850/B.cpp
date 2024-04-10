#include<cstdio>
#include<algorithm>
using namespace std;
int n, C[2010000], X, Y, K, M = 1000000;
long long S1[2010000], S2[2010000], res;
int main(){
    int i, a, j;
    scanf("%d%d%d",&n,&X,&Y);
    K = X/Y;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        C[a]++;
    }
    for(i=1;i<=M+M;i++){
        S1[i]=S1[i-1]+C[i];
        S2[i]=S2[i-1]-1ll*i*C[i];
    }
    res = 9e18;
    for(i=2;i<=M;i++){
        long long SA = 0, SB = 0;
        for(j=0;j<M;j+=i){
            if(i-1 <= K){
                SB += (S2[j+i] - S2[j] + (S1[j+i] - S1[j])*(j+i));
            }
            else{
                SA += (S1[j+i-K-1] - S1[j]);
                SB += (S2[j+i] - S2[j+i-K-1] + (S1[j+i] - S1[j+i-K-1])*(j+i));
            }
        }
        if(1e18/X < SA || 1e18/Y < SB)continue;
        res = min(res, SA*X + SB*Y);
    }
    printf("%lld\n",res);
}