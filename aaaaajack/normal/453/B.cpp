#include<cstdio>
#include<cstring>
#define MSK (1<<17)
#define N 110
#define inf 0x3f3f3f3f
#define iabs(n) ((n)>0?(n):-(n))
using namespace std;
int prm[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int dp[N][MSK],use[N][MSK],a[N];
int mask[70]={0},ans[N];
int main(){
	memset(dp,0x3f,sizeof(dp));
	int i,j,k,n,sel;
	dp[0][0]=0;
	for(i=1;i<=60;i++){
		for(j=0;j<17;j++){
			if(i%prm[j]==0) mask[i]|=(1<<j);
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		for(j=0;j<MSK;j++){
			if(dp[i][j]==inf) continue;
			for(k=1;k<2*a[i];k++){
				if(j&mask[k]) continue;
				if(dp[i][j]+iabs(k-a[i])<dp[i+1][j|mask[k]]){
					dp[i+1][j|mask[k]]=dp[i][j]+iabs(k-a[i]);
					use[i+1][j|mask[k]]=k;
				}
			}
		}
	}
	sel=0;
	for(i=0;i<MSK;i++){
		if(dp[n][i]<dp[n][sel]) sel=i;
	}
	for(i=n;i>=1;i--){
		ans[i]=use[i][sel];
		sel&=~(mask[ans[i]]);
	}
	for(i=1;i<=n;i++){
		if(i<n) printf("%d ",ans[i]);
		else printf("%d\n",ans[i]);
	}
	return 0;
}