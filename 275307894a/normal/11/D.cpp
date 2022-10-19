#include<cstdio>
#include<cstring>
using namespace std;
int n,m,x,y,z,now,lg[1000039];
long long f[1000039][20],ans;
int s[39][39];
int main(){
	//freopen("1.in","r",stdin);
	register int i,j,k,h;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d%d",&x,&y),s[x][y]=s[y][x]=1;
	for(i=1;i<(1<<n);i++) lg[i]=lg[i-1]+(i==1<<lg[i-1]);
	for(i=1;i<=n;i++) f[1<<i-1][i]=1;
	for(i=1;i<(1<<n);i++){
		for(j=1;j<=n;j++){
			if(!(i&(1<<j-1))) continue;
			now=lg[i&-i];
			for(k=now;k<=n;k++){
				if(!s[j][k]) continue;
				if(i&(1<<k-1)){
					if(k==now) ans+=f[i][j];
				}
				else f[i|(1<<k-1)][k]+=f[i][j];
			}
		}
	}
	printf("%lld\n",(ans-m)/2);
}