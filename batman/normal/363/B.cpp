#include<stdio.h>
int S[150005];
int main(){
    int n,k,ans=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&S[i]),S[i]+=S[i-1];
    for(int j=0;j<=n-k;j++) if(S[ans+k]-S[ans]>S[j+k]-S[j]) ans=j;
    printf("%d\n",ans+1);
}