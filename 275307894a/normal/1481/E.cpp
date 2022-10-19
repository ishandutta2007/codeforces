#include<cstdio>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,dp[500039],l[500039],r[500039],now,a[500039],siz[500039],g[500039],f[500039];
int main(){
///	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),siz[a[i]]++,l[a[i]]=l[a[i]]?l[a[i]]:i,r[a[i]]=i;
	for(i=1;i<=n;i++) if(l[i]) g[l[i]]=i;
	for(i=n;i;i--){
		dp[i]=dp[i+1];f[a[i]]++;
		if(g[i]) dp[i]=max(dp[i],dp[r[g[i]]+1]+siz[g[i]]);
		else dp[i]=max(dp[i],f[a[i]]);
	}
	printf("%d\n",n-dp[1]);
}////////////////