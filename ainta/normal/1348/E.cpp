#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K;
long long SA, SB;
int D[510][510];
int main(){
    int i, j, k;
    scanf("%d%d",&n,&K);
    D[0][0]=1;
    for(i=1;i<=n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        SA+=a,SB+=b;
        for(j=0;j<=min(K+K,a);j++){
            if( (a-j+K-1)/K == (a-j+b+K)/K   )continue;
            for(k=0;k<K;k++){
                if(D[i-1][k])D[i][(k+j)%K] = 1;
            }
        }
    }
    long long res=0;
    for(i=0;i<K;i++){
        if(!D[n][i])continue;
        int z = (SA+SB-i)%K;
        res=max(res,(SA+SB-z-i)/K);
    }
    printf("%lld\n",res);
}