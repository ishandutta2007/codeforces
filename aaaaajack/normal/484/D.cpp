#include<bits/stdc++.h>
#define N 1001000
using namespace std;
int a[N];
long long dp[3],nxt[3];
long long inf=-(1LL<<60);
int main(){
	int n;
	scanf("%d",&n);
	dp[0]=dp[2]=inf;
	fill(nxt,nxt+3,inf);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=-1;j<=1;j++){
			for(int k=0;k<3;k++){
				if(j+k>=0&&j+k<3){
					nxt[j+k]=max(nxt[j+k],dp[k]+j*a[i]);
				}
			}
		}
		for(int k=0;k<3;k++){
			dp[k]=nxt[k];
			nxt[k]=inf;
		}
	}
	printf("%lld\n",dp[1]);
	return 0;
}