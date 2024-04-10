#include<cstdio>
#include<algorithm>
#define SZ 524288
using namespace std;
int n;
long long M, w[401000], D[401000], S[401000], DS[401000], IT[SZ+SZ];
void Ins(int a, long long x){
    a += SZ;
    IT[a] = x;
    while(a != 1){
        a>>=1;
        IT[a] = min(IT[a*2],IT[a*2+1]);
    }
}
long long Min(int b, int e){
    long long r = 5e18;
    b+=SZ,e+=SZ;
    while(b<=e){
        r=min(r,min(IT[b],IT[e]));
        b=(b+1)>>1,e=(e-1)>>1;
    }
    return r;
}
int main(){
    int i;
    scanf("%d%lld",&n,&M);
    for(i=1;i<=n*2-1;i++){
        scanf("%lld",&w[i]);
        S[i] = S[i-1] + w[i];
    }
    for(i=1;i<=n;i++)D[i] = min(M, w[i*2-1]);
    int pv = 0;
    DS[1] = D[1];
    Ins(1, S[2] - D[1]);
    for(i=2;i<=n;i++){
        while(S[i*2-1] - S[pv] >= M) pv++;
        int t = (pv+1)/2;
        if(t!=0){
            D[i] = max(D[i], M - (DS[i-1] - DS[t-1]));
        }
        long long tp = Min(t, i-1);
        D[i] = max(D[i], (S[i*2-1]-DS[i-1]) - tp);
        DS[i] = DS[i-1] + D[i];
        Ins(i, S[i*2] - DS[i]);
    }
    printf("%lld\n",DS[n]);
}