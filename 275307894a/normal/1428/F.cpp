#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[1000039],now,pt;
long long f[1000039],g[1000039],ans,tot,pus;
char c;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		c=getchar();
		while(c<'0'||c>'9') c=getchar();
		a[i]=c;
	}
	for(i=n;i;i--){
		if(a[i]=='0'){
			for(j=1;j<=now;j++) f[j]++;
			now=0,ans+=tot,pus=0,f[0]++;
		}
		else{
			now++;
			tot-=f[now-1]*(now-1);
			f[now]+=f[now-1];
			tot+=f[now-1]*now;
			f[now-1]=0;
			tot+=now;
			ans+=tot;
		}
	//	printf("%lld\n",tot);
	}
	printf("%lld\n",ans);
}