#include<stdio.h>
#include<algorithm>
using namespace std;
int n, k, x, w[201000];
long long L[201000], R[201000], Res;
int main(){
    int i;
    long long t = 1;
    scanf("%d%d%d",&n,&k,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        L[i] = R[i] = w[i];
    }
    for(i=2;i<=n;i++)L[i]|=L[i-1];
    for(i=n-1;i>=1;i--)R[i]|=R[i+1];
    for(i=1;i<=k;i++)t=t*x;
    for(i=1;i<=n;i++){
        Res= max(Res,L[i-1]|R[i+1]|(t*w[i]));
    }
    printf("%lld\n",Res);
}