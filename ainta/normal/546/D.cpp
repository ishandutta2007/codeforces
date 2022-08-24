
#include<stdio.h>
int P[5010000];
long long S[5010000], w[5010000];
int main()
{
    int i, j, T, a, b;
    for(i=1;i<=5000000;i++)P[i]=i;
    for(i=2;i<=5000000;i++){
        if(w[i])continue;
        for(j=i;j<=5000000;j+=i){
            w[j]++;
            P[j]/=i;
        }
    }
    for(i=1;i<=5000000;i++){
        w[i] += w[P[i]];
    }
    for(i=2;i<=5000000;i++)S[i]=S[i-1]+w[i];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        printf("%lld\n",S[a]-S[b]);
    }
}