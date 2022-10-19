#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,f[1000039],x,y,ans=1e9,tot,pus,a[1000039],s[1000039];
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[x]=y;
		tot=max(tot,x);
		s[x]++;
	}
	for(i=0;i<=tot;i++) s[i]+=s[i-1];
	for(i=0;i<=tot;i++){
		if(!a[i]) f[i]=f[i-1];
		else if(i<=a[i]) f[i]=s[i-1];
		else f[i]=f[i-a[i]-1]+(s[i-1]-s[i-a[i]-1]);
		if(a[i]) pus++;
		ans=min(ans,n+f[i]-pus);
	}
	printf("%d\n",ans);
}