#include<stdio.h>
int n, w[2010000];
int main()
{
    int i, j, pv, nxt;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        w[i]=i;
    }
    for(i=2;i<=n;i++){
        nxt = n+i-1;
        pv=((n-1)/i)*i+1 + (i-2);
        for(;pv>=i-1;pv-=i){
            w[nxt] = w[pv];
            nxt = pv;
        }
    }
    for(i=n;i<2*n;i++)printf("%d ",w[i]);
}