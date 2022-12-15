#include<stdio.h>
#include<string.h>
#include<algorithm>

#define V_ 1000005
typedef long long lld;
int V, E;
int Dg[V_];
lld all, tr;

int main(){
    scanf("%d%d",&V,&E);
    while(E--){
        int a, b; scanf("%d%d",&a,&b);
        Dg[a]++; Dg[b]++;
    }

    all = (lld)V * (V-1) * (V-2) / 6;
    for(int i=1; i<=V; i++) tr += (lld)Dg[i] * (V - Dg[i] - 1);
    printf("%I64d\n",all - tr / 2);
    return 0;
}