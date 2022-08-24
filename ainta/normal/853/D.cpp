#include<cstdio>
#include<algorithm>
using namespace std;
int n, D[310], TD[310], S, w[301000], res = 2e9;
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=0;i<=300;i++)TD[i]=D[i]=2e9;
    D[0]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<=300;j++){
            int t =min(w[i],j*100);
            TD[j-t/100] = min(TD[j-t/100],D[j] + w[i] - min(w[i],j*100));
        }
        for(j=0;j<=300;j++){
            TD[j + w[i]/1000] = min(D[j] + w[i], TD[j + w[i]/1000]);
        }
        for(j=0;j<=300;j++)D[j]=TD[j],TD[j]=2e9;
    }
    for(i=0;i<=300;i++)res = min(res, D[i]);
    printf("%d\n",res);
}