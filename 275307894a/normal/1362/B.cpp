#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[10039],f[10039],q[10039],maxn,t,ans,flag;
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<=1024;i++) q[i]=0;
		maxn=0;ans=-1;
		for(i=1;i<=n;i++)scanf("%d",&a[i]),q[a[i]]++,maxn=max(maxn,a[i]);
		for(i=1;i<=1023;i++){
			for(j=0;j<=1023;j++)f[j]=0;
			for(j=1;j<=n;j++) f[a[j]^i]++;
			flag=0;
			for(j=0;j<=1023;j++){
				if(f[j]!=q[j]){flag=1;break;}
			}
			if(!flag){ans=i;break;}
		}
		if(ans!=-1) printf("%d\n",ans);
		else printf("-1\n");
	}
}