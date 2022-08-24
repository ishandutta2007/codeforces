#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long B, E, T, w[101000], bb[101000], ee[101000], res = 1e18, rr;
int main(){
    int i;
    scanf("%lld%lld%lld",&B,&E,&T);
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld",&w[i]);
    long long t = B;
    for(i=1;i<=n;i++){
        if(t < w[i] && t <= E-T){
            printf("%lld\n",t);
            return 0;
        }
        if(res > t - (w[i] - 1) && t <= E-T) res = t - (w[i] - 1), rr = w[i]-1;
        bb[i] = max(t, w[i]);
        ee[i] = bb[i] + T;
        t = ee[i];
    }
    if(t <= E-T){
        printf("%lld\n",E-T);
        return 0;
    }
    else printf("%lld\n",rr);
}