#include<cstdio>
using namespace std;
int n,m,k,x,y,z,d[39][39],xs,ys,dp[17000039],g1[17000039],g2[17000039],a[139],b[139],dis[139],nowx,nowy;
inline int secpow(int x) {return x*x;}
int main() {
//	freopen("1.in","r",stdin);
	register int i,j,h;
	scanf("%d%d",&xs,&ys);
	scanf("%d",&n);
	for(i=1; i<=n; i++) scanf("%d%d",&a[i],&b[i]),dis[i]=secpow(xs-a[i])+secpow(ys-b[i]);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			d[i][j]=secpow(a[i]-a[j])+secpow(b[i]-b[j]);
		}
	}
	k=(1<<n)-1;
	for(i=1; i<=k; i++) dp[i]=1e9;
	for(i=0; i<=k; i++) {
		for(j=1; j<=n; j++) {
			if(i&(1<<j-1))continue;
			nowx=1<<j-1;
			for(h=1; h<=n; h++) {
				if(i&(1<<h-1))continue;
				nowy=1<<h-1;
				if(dp[i|nowx|nowy]>dis[j]+dis[h]+d[j][h]+dp[i]) {
					dp[i|nowx|nowy]=dis[j]+dis[h]+d[j][h]+dp[i];
					g1[i|nowx|nowy]=j;g2[i|nowy|nowx]=h;
				}
			}
			break;
		}
	}
	printf("%d\n",dp[k]);
	printf("0 ");
	while(k) {
		if(g1[k]==g2[k]) printf("%d ",g1[k]),k-=1<<g1[k]-1;
		else printf("%d %d ",g1[k],g2[k]),k-=(1<<g1[k]-1)+(1<<g2[k]-1);
		printf("0 ");
	}
}