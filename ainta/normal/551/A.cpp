#include<stdio.h>
int n, w[2010];
int main(){
    int i, j, c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&w[i]);
    for(i=1;i<=n;i++){
        c = 1;
        for(j=1;j<=n;j++){
            if(w[i] < w[j])c++;
        }
        printf("%d ",c);
    }
}