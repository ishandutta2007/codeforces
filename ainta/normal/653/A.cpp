#include<stdio.h>
int n, i, w[100], j, k, ck;
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(w[i]+1==w[j]&&w[j]+1==w[k])ck=1;
            }
        }
    }
    printf(ck?"YES\n":"NO\n");
}