#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[300039],st1[300039][20],st2[300039][20],lg[300039],dp[300039],tot,rs,ans,l,r,mid;
inline int find1(int l,int r){
	ans=lg[r-l+1]-1;
	return min(st1[l][ans],st1[r-(1<<ans)+1][ans]);
}
inline int find2(int l,int r){
	ans=lg[r-l+1]-1;
	return max(st2[l][ans],st2[r-(1<<ans)+1][ans]);
}
inline int check(int mid){
	register int i;
	memset(dp,0,sizeof(dp));
	rs=0;tot=0;dp[0]=1;
	for(i=1;i<=n;i++){
		if(i>=m) tot+=dp[i-m];
		while(rs<i&&find2(rs+1,i)-find1(rs+1,i)>mid) tot-=dp[rs],rs++;
		if(tot>0) dp[i]=1; 
		else dp[i]=0;
	}
	return dp[n];
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(i=n;i>=1;i--){
		st1[i][0]=st2[i][0]=a[i];
		for(j=1;i+(1<<j)-1<=n;j++) st1[i][j]=min(st1[i][j-1],st1[i+(1<<j-1)][j-1]),st2[i][j]=max(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
	}
	l=-1;r=2e9;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
}