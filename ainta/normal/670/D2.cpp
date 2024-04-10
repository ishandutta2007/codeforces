#include<stdio.h>
#include<algorithm>
using namespace std;
int n, M, A[101000], B[101000];
bool Possible(long long K){
    int i;
    long long S = 0;
    for(i=1;i<=n;i++){
        S += max(K*A[i]-B[i], (long long)0);
        if(S > M)return false;
    }
    return true;
}
int main(){
    int i;
    scanf("%d%d",&n,&M);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&B[i]);
    }
    long long b = 1, e = 1e10, K, res = 0;
    while(b<=e){
        K = (b+e)/2;
        if(Possible(K)){
            res = K;
            b = K + 1;
        }
        else{
            e = K - 1;
        }
    }
    printf("%lld\n",res);
}