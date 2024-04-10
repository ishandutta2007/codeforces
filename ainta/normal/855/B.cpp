#include<cstdio>
#include<algorithm>
using namespace std;
long long LMn[101000], LMx[101000], RMn[101000], RMx[101000], w[101000], p, q, r, res = -5e18;
int n;
int main(){
    scanf("%d%lld%lld%lld",&n,&p,&q,&r);
    int i;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    LMn[0]=RMn[n+1] = 2e9;
    LMx[0]=RMx[n+1] = -2e9;
    for(i=1;i<=n;i++){
        LMn[i] = min(LMn[i-1],w[i]);
        LMx[i] = max(LMx[i-1],w[i]);
    }
    for(i=n;i>=1;i--){
        RMn[i] = min(RMn[i+1],w[i]);
        RMx[i] = max(RMx[i+1],w[i]);
    }
    for(i=1;i<=n;i++){
        res = max(res, LMn[i]*p+w[i]*q+RMn[i]*r);
        res = max(res, LMn[i]*p+w[i]*q+RMx[i]*r);
        res = max(res, LMx[i]*p+w[i]*q+RMn[i]*r);
        res = max(res, LMx[i]*p+w[i]*q+RMx[i]*r);
    }
    printf("%lld\n",res);
}