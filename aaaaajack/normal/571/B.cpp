#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 300100
#define K 5010
using namespace std;
int a[N],dp[K][K];
int main(){
	int n,k,sum,q,r;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	q=n/k;
	r=n%k;
	sum=a[n]-a[1];
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=r;j++){
			int bst=j?max(dp[i-1][j],dp[i-1][j-1]):dp[i-1][j];
			if(bst<0) continue; 
			if(i==k&&j==r) dp[i][j]=bst;
			else dp[i][j]=bst+a[i*q+j+1]-a[i*q+j];
		}
	}
	printf("%d\n",sum-dp[k][r]);
	return 0;
}