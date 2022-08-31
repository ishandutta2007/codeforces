#include<stdio.h>
long long DP[51];
void Do(int ed, int n, long long K){
    if(!n)return;
    if(DP[n-1] < K){
        K-=DP[n-1];
        printf("%d %d ",ed+2,ed+1);
        Do(ed+2,n-2,K);
        return;
    }
    printf("%d ",ed+1);
    Do(ed+1,n-1,K);
}
int main(){
    int i, j, n;
    long long K;
    scanf("%d%lld",&n,&K);
    DP[0] = DP[1]=1,DP[2]=2;
    for(i=3;i<=n;i++)DP[i]=DP[i-1]+DP[i-2];
    Do(0, n,K);
}