#include<stdio.h>
#include<algorithm>
using namespace std;
long long n, L[201000], BB[201000], w[201000], pv, x;
long long r, TT, R[201000], RC, CurT;
int main(){
    long long i;
    scanf("%lld%lld",&n,&r);
    for(i=1;i<=n;i++)scanf("%lld",&L[i]);
    for(i=1;i<=n;i++){
        scanf("%lld",&BB[i]);
        if(BB[i] < L[i]){
            printf("-1\n");
            return 0;
        }
        if(BB[i]>=L[i]*2)w[i] = 0;
        else w[i] = 2*L[i]-BB[i];
    }
    pv = 1, x = 0;
    while(1){
        if(pv>n)break;
        if(TT){
            if(TT >= L[pv] - x){
                TT -= L[pv] - x;
                CurT += L[pv] - x;
                pv++;
                x = 0;
                continue;
            }
            else{
                CurT += TT;
                x += TT;
                w[pv] -= TT;
                if(w[pv]<0)w[pv]=0;
                TT = 0;
            }
        }
        if(!w[pv]){
            CurT += (L[pv] - x)*2;
            pv++;
            x=0;
            continue;
        }
        long long tp = (w[pv]+r-1)/r;
        if(RC+tp > 100000){
            RC += tp;
            TT = r - w[pv]%r;
            if(TT==r)TT=0;
            CurT += (L[pv] - w[pv] - x)*2 + w[pv];
            x = 0;
            pv++;
            continue;
        }
        CurT += (L[pv] - w[pv] - x)*2;
        for(i=0;i<tp;i++){
            R[++RC] = CurT + r * i;
        }
        TT = r - w[pv]%r;
        if(TT==r)TT=0;
        CurT += w[pv];
        x = 0;
        pv++;
    }
    printf("%lld\n",RC);
    if(RC<=100000)for(i=1;i<=RC;i++)printf("%lld ",R[i]);
}