#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[2010];
long long D[10100], C[5010], S, S2, ss;
double Res;
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            C[max(w[j],w[i])-min(w[j],w[i])]++;
            S2++;
        }
    }
    for(i=1;i<=5000;i++)for(j=1;j<=5000;j++)D[i+j]+=C[i]*C[j];
    for(i=1;i<=10000;i++)S+=D[i];
    for(i=5000;i>=1;i--){
        ss += C[i+1];
        Res += (double)D[i]/S*ss/S2;
    }
    printf("%.11lf\n",Res);
}