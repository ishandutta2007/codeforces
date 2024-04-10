#include<cstdio>
#include<algorithm>
#define N 510
#define inf 1023456789
using namespace std;
int dp[N][N];
int a[N];
int f(int l,int r){
	if(l>=r) return 1;
	if(dp[l][r]) return dp[l][r];
	dp[l][r]=inf;
	if(a[l]==a[r]){
		dp[l][r]=f(l+1,r-1);
	}
	for(int i=l;i<r;i++){
		dp[l][r]=min(dp[l][r],f(l,i)+f(i+1,r));
	}
	return dp[l][r];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("%d\n",f(0,n-1));
	return 0;
}