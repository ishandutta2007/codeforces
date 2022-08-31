#include<stdio.h>
int Deg[10100], n;
int main(){
    int a,b, i, res = 0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        Deg[a]++,Deg[b]++;
    }
    for(i=1;i<=n;i++){
        res += Deg[i]*(Deg[i]-1)/2;
    }
    printf("%d\n",res);
}