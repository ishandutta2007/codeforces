#include<cstdio>
#include<algorithm>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,now[300039],tots[300039],cnt,ans,top[300039],ends[300039],dp[300039],l,r,mid,a[300039];
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) top[i]=0,ends[i]=1e9;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),now[i]=a[i];
		sort(now+1,now+n+1);
		now[0]=now[1]-1;
		for(i=1;i<=n;i++){
			tots[i]=tots[i-1];
			if(now[i-1]!=now[i]) tots[i]++;
		}
		for(i=1;i<=n;i++){
			l=0;r=n+1;
			while(l+1<r){
				mid=(l+r)>>1;
				if(now[mid]<a[i]) l=mid;
				else r=mid;
			}
			a[i]=tots[r];
			if(!top[a[i]]) top[a[i]]=i;
			ends[a[i]]=i;
		}
		ans=0;
		for(i=1;i<=tots[n];i++){
			if(top[i]>ends[i-1]) dp[i]=dp[i-1]+1;
			else dp[i]=1;
			ans=max(ans,dp[i]);
		}
		printf("%d\n",tots[n]-ans);
	}
}