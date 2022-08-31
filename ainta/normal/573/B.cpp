#include<stdio.h>
#include<algorithm>
using namespace std;
int M, n, w[101000], L[101000], R[101000], Res;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    M = 0;
    for(i=1;i<=n;i++){
        if(M < i - w[i]) M = i - w[i];
        L[i] = i - M;
    }
    M = n + 1;
    for(i=n;i>=1;i--){
        if(M > i + w[i]) M = i + w[i];
        R[i] = M - i;
        Res = max(min(R[i],L[i]),Res);
    }
    printf("%d\n",Res);
}