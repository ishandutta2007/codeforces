#include<cstdio>
#include<cstring>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,x,y,z,now,last;
unsigned long long dp[2][1200039],ans=1e19,k;
struct yyy{unsigned long long x,y,z;}s[139];
inline bool cmp(yyy x,yyy y){return x.y<y.y;}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d%llu",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%llu%llu%d",&s[i].x,&s[i].y,&x);
		while(x--) scanf("%d",&y),s[i].z+=1<<y-1;
	}
	sort(s+1,s+n+1,cmp);
	memset(dp,0x7f,sizeof(dp));
	dp[0][0]=0;
	now=0;last=1;
	for(i=1;i<=n;i++){
		now^=1;last^=1;
		for(j=0;j<(1<<m);j++) dp[now][j]=dp[last][j];
		for(j=0;j<(1<<m);j++)dp[now][j|s[i].z]=min(dp[last][j]+s[i].x,dp[now][j|s[i].z]);
		ans=min(ans,dp[now][(1<<m)-1]+s[i].y*k);
	}
	if(ans>=9e18) printf("-1");
	else printf("%llu\n",ans);
}