#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[3][100001], a[2][100001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[0][i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[1][i]);
    }
    dp[0][0]=a[0][0];
    dp[1][0]=a[1][0];
    dp[2][0]=0;
    for(int i=1;i<n;i++){
        dp[0][i] = max(dp[1][i-1],dp[2][i-1])+a[0][i];
        dp[1][i] = max(dp[0][i-1],dp[2][i-1])+a[1][i];
        dp[2][i] = max(dp[0][i-1],dp[1][i-1]);
    }
    printf("%lld\n",max(max(dp[0][n-1],dp[1][n-1]),dp[2][n-1]));
}