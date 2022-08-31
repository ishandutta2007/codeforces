#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[101000], odd, res;
int D[101000];
int main(){
    int i, pv = 1, pv2 = 1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(i==1){
            D[i] = 20;
            continue;
        }
        D[i] = D[i-1]+20;
        while(w[pv] + 90 <= w[i])pv++;
        while(w[pv2] + 1440 <= w[i])pv2++;
        D[i] = min(D[i],D[pv-1]+50);
        D[i] = min(D[i],D[pv2-1]+120);
    }
    for(i=1;i<=n;i++){
        printf("%d\n",D[i]-D[i-1]);
    }
}