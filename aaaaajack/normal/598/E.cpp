#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1023456789
using namespace std;
int dp[31][31][51];
int cost(int a,int b,int c){
    int now=inf;
    if(c>a*b) return inf;
    if(c==0||c==a*b) return 0;
    if(dp[a][b][c]>=0) return dp[a][b][c];
    for(int i=1;i<=a-i;i++){
        for(int j=0;j<=c;j++){
            now=min(now,b*b+cost(i,b,j)+cost(a-i,b,c-j));
        }
    }
    for(int i=1;i<=b-i;i++){
        for(int j=0;j<=c;j++){
            now=min(now,a*a+cost(a,i,j)+cost(a,b-i,c-j));
        }
    }
    return dp[a][b][c]=now;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int t,n,m,k;
    scanf("%d%",&t);
    for(int i=0;i<t;i++){
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",cost(n,m,k));
    }
    return 0;
}