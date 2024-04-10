#include<stdio.h>
#include<algorithm>
using namespace std;
#define N_ 1010000
int n, m, w[N_], v[N_], C[N_], D[N_], S[N_], TP[N_];
int main(){
    int i, x, j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        if(v[i])continue;
        x = i;
        int c = 0;
        while(1){
            c++;
            v[x]=1;
            x = w[x];
            if(x==i)break;
        }
        C[c]++;
    }
    D[0] = 1;
    int ss = 0;
    for(i=1;i<=n && !D[m];i++){
        if(!C[i])continue;
        int mod = 0, x = i*C[i];
        S[0] = 1;
        ss += x;
        TP[0] = 1;
        for(j=1;j<=ss;j++){
            mod++;
            if(mod==i)mod=0;
            int tp = D[j];
            
            if(S[mod])D[j] = 1;
            
            S[mod] += tp;
            TP[j] = tp;
            if(j>=x)S[mod] -= TP[j-x];
        }
        for(j=0;j<mod;j++)S[j]=0;
    }
    if(D[m])printf("%d ",m);
    else printf("%d ",m+1);
    int s = 0;
    for(i=1;i<=n;i++){
        if(C[i]&&i%2)s+=C[i];
    }
    if(m * 2 <= n-s)printf("%d\n",m*2);
    else printf("%d\n",min(n-s + (m*2 - (n-s))/2,n));
}