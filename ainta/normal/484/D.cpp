#include<stdio.h>
#include<algorithm>
using namespace std;
int w[1010000], n, UU, DD;
long long D[1010000];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=2;i<=n;i++){
        if(w[i-1]<w[i])UU = i-1;
        if(w[i-1]>w[i])DD = i-1;
        D[i] = max(D[UU]+w[UU+1]-w[i],D[DD]+w[i]-w[DD+1]);
        if(UU != i-1)D[i] = max(D[i],D[UU+1]+w[UU+2]-w[i]);
        if(DD != i-1)D[i] = max(D[i],D[DD+1]+w[i]-w[DD+2]);
    }
    printf("%lld\n",D[n]);
}