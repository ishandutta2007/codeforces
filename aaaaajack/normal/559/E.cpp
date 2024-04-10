#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
using namespace std;
long long dp[N<<1][N<<1],ndp[N<<1][N<<1];
int a[N],l[N],id[N];
int cmp(int i,int j){
	return a[i]<a[j];
}
inline int get_val(int x){
	if(x==0) return -1023456789;
	return x&1?a[x>>1]+l[x>>1]:a[x>>1];
}
int main(){
	memset(dp,-1,sizeof(dp));
	memset(ndp,-1,sizeof(ndp));
	dp[0][0]=ndp[0][0]=0;
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&l[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n*2+1;j++){
			for(int k=0;k<=n*2+1;k++){
				int x=id[i];
				if(dp[j][k]<0) continue;
				if(a[x]>get_val(k)){
					ndp[k][x*2+1]=max(ndp[k][x*2+1],dp[j][k]+l[x]);
					ndp[k][x*2]=max(ndp[k][x*2],dp[j][k]+a[x]-max(a[x]-l[x],get_val(k)));
				}
				else{
					if(a[x]+l[x]>get_val(k)){
						ndp[k][x*2+1]=max(ndp[k][x*2+1],dp[j][k]+a[x]+l[x]-get_val(k));
					}
					if(a[x]-l[x]<a[k>>1]&&a[k>>1]>get_val(j)){
						ndp[x*2][k]=max(ndp[x*2][k],dp[j][k]+a[k>>1]-max(a[x]-l[x],get_val(j)));
					}
				}
			}
		}
		memcpy(dp,ndp,sizeof(dp));
	}
	for(int j=0;j<=n*2+1;j++){
		for(int k=0;k<=n*2+1;k++){
			ans=max(ans,dp[j][k]);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}