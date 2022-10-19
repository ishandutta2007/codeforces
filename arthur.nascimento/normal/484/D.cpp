#include <stdio.h>
#include <algorithm>
using namespace std;
int n,vet[1000010],ult,at,mi[1000010][25],ma[1000010][25];
long long int dp[1000010],resp;
const long long int INF=1000000000000000010; 

long long int soc(long long int a,long long int b){ 
    if(a>b) return -INF;
    if(a==b) return 0;
    long long int c=b-a+1,d=-1;
    while(c){
        c/=2;
        d++;
    }
    return max(ma[a][d],ma[b-(1LL<<d)+1][d])-min(mi[a][d],mi[b-(1LL<<d)+1][d]);
}

int main(){
//  soc(0,6);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&vet[i]);
        mi[i][0]=ma[i][0]=vet[i];
    }
    for(int j=1;j<25;j++){
        for(int i=0;i<n;i++){
            mi[i][j]=min( mi[i][j-1] , mi[min(n-1,i+(1<<(j-1)))][j-1] );
            ma[i][j]=max( ma[i][j-1] , ma[min(n-1,i+(1<<(j-1)))][j-1] );
        }
    }
    ult=0;
    for(int i=1;i<n;i++) dp[i]=soc(0,i);
    for(int i=1;i<n;i++){
        if( (long long)(vet[ult+1]-vet[ult])*(vet[i+1]-vet[i])<=0 || i==n-1){
            dp[i]=max( dp[i] , dp[ult]+soc(ult+1,i) );
            if(ult>0) dp[i]=max( dp[i] , dp[ult-1]+soc(ult,i) );
            dp[i-1]=max( dp[i-1] , dp[ult]+soc(ult+1,i-1) );
            if(ult>0) dp[i-1]=max( dp[i-1] , dp[ult-1]+soc(ult,i-1) );
            ult=i;
            resp=max(max(dp[i],dp[i-1]),resp);
        }
    }
    printf("%I64d\n",resp);
    return 0;
}