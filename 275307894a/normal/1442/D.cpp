#include<cstdio>
#include<vector>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t[3039],l,r,mid,now,last,qs[3039],head,tail;
long long dp[3039],ans,tot[3039];
vector<long long> f[3039];
inline void slove(int l,int r){
	if(l==r){
		long long pus=0;
		ans=max(ans,dp[m]);
		for(int i=0;i<min(t[l],m);i++){
			pus+=f[l][i];
			ans=max(ans,dp[m-i-1]+pus);
		}
		return;
	}
	int mid=l+r>>1,i,j;
	long long w[3039];
	for(i=1;i<=m;i++) w[i]=dp[i];
	for(i=l;i<=mid;i++){
		for(j=m;j>=t[i];j--){
			dp[j]=max(dp[j],dp[j-t[i]]+tot[i]);
		}
	}
	slove(mid+1,r);
	for(i=1;i<=m;i++) dp[i]=w[i];
	for(i=mid+1;i<=r;i++){
		for(j=m;j>=t[i];j--){
			dp[j]=max(dp[j],dp[j-t[i]]+tot[i]);
		}
	}
	slove(l,mid);
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&t[i]);
		for(j=0;j<t[i];j++) scanf("%d",&x),f[i].push_back(x),tot[i]+=x;
	}
	slove(1,n);
	printf("%lld\n",ans);
}