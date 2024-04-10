#include<stdio.h>
#include<algorithm>
using namespace std;
long long S, w[301000];
int main(){
    int i, n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        S += min(n,i+1) * w[i];
    }
    printf("%lld\n",S);
}