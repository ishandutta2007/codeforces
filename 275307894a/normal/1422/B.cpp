#include<cstdio>
#include<algorithm>
#include<cstring>
#define abs(x) ((x)>(0)?(x):-(x))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[139][139],t,tot;
long long ans,pus,s[139];
int main(){
	register int i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
		}
		for(i=1;i<=n/2;i++){
			for(j=1;j<=m/2;j++){
				s[1]=a[i][j];s[2]=a[n-i+1][j];s[3]=a[i][m-j+1];s[4]=a[n-i+1][m-j+1];
				pus=1e15;
				for(k=1;k<=4;k++){
					pus=min(pus,abs(s[1]-s[k])+abs(s[2]-s[k])+abs(s[3]-s[k])+abs(s[4]-s[k]));
				}
				ans+=pus;
			}
		}
		if(n&1){
			for(i=1;i<=m/2;i++){
				s[1]=a[n/2+1][i];s[2]=a[n/2+1][m-i+1];
				pus=1e15;
				for(k=1;k<=2;k++) pus=min(pus,abs(s[1]-s[k])+abs(s[2]-s[k]));
				ans+=pus;
			}
		}
		if(m&1){
			for(i=1;i<=n/2;i++){
				s[1]=a[i][m/2+1];s[2]=a[n-i+1][m/2+1];
				pus=1e15;
				for(k=1;k<=2;k++) pus=min(pus,abs(s[1]-s[k])+abs(s[2]-s[k]));
				ans+=pus;
			}
		}
		printf("%lld\n",ans);
	}
}