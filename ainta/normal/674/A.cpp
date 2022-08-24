#include<stdio.h>
int C[5010], w[5010], n, Mx, x, Res[5010];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)C[j]=0;
        Mx = 0, x = -1;
        for(j=i;j<=n;j++){
            C[w[j]]++;
            if(Mx < C[w[j]] || (Mx == C[w[j]] && x>w[j])){
                Mx = C[w[j]];
                x = w[j];
            }
            Res[x]++;
        }
    }
    for(i=1;i<=n;i++)printf("%d ",Res[i]);
}