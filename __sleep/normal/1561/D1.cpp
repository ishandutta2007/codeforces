#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=4000002;
int dp[4000002],m,n;
// inline int lb(int x){return x&-x;}
// inline void add(int x,int y){
//     for(;x<N;x+=lb(x))
// }
int main(){
    scanf("%d%d",&n,&m); 
    dp[1]=1;int sum=1;
    for(int i=2;i<=n;i++){
        dp[i]=sum;
        for(int l=2,r;l<=i;l=r+1){
            r=i/(i/l);
            dp[i]=(dp[i]+(r-l+1ll)*dp[i/l])%m;
        }
        sum=(sum+dp[i])%m;
    }
    printf("%d\n",dp[n]);
    return 0;
}