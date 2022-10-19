#include<cstdio>
#include<cstring> 
#define N 100000
#define I inline
#define re register
#define ll long long
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b)) 
using namespace std;
int n,k,a[N+5],f[N+5],ls=1,rs;ll w,g[N+5],dp[N+5]; 
I void get(int l,int r){
	while(ls>l) w+=f[a[--ls]]++;
	while(rs<r) w+=f[a[++rs]]++;
	while(ls<l) w-=--f[a[ls++]];
	while(rs>r) w-=--f[a[rs--]];
}
I void solve(int l,int r,int x,int y){
	if(x>y) return;int mid=x+y>>1,i,p=mid,nowl=ls,nowr=rs;//printf("%d %d %d %d\n",l,r,x,y);
	for(i=min(mid,r);i>=l;i--) get(i,mid),dp[mid]>g[i-1]+w&&(dp[mid]=g[i-1]+w,p=i);
	solve(l,p,x,mid-1);solve(p,r,mid+1,y);get(nowl,nowr);
}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d%d",&n,&k);memset(dp,0x3f,sizeof(dp));dp[0]=0;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++) g[j]=dp[j];solve(1,n,1,n);
	//	for(j=1;j<=n;j++) printf("%d ",dp[j]);putchar('\n');
	}
	printf("%lld\n",dp[n]);
}