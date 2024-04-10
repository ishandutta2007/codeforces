#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,ans,tot,now;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);ans=1e9;
		for(i=0;i<=40;i++){
			tot=i;
			now=n;
			if(!i&&m==1) continue;
			while(now) now/=m+i,tot++;
			ans=min(ans,tot);
		}
		printf("%d\n",ans);
	}
}