#include<cstdio>
using namespace std;
int n,m,s,x,y,tot,pus,a;
long long f[539][539],ans,mod;
int main(){
	register int i,j,k,now,last;
	scanf("%d%d%d%lld",&n,&m,&s,&mod);
	f[0][0]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(j=1;j<=m;j++){
			for(k=a;k<=s;k++){
				f[j][k]=(f[j][k]+f[j-1][k-a])%mod;
			}
		}
	}
	for(i=0;i<=s;i++)ans=(ans+f[m][i])%mod;
	printf("%lld\n",ans);
}