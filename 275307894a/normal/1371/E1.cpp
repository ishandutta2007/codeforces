#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,p,x,y,z,t[100039],minn=1e9,maxn,a[100039],flag,ans[100039],head;
int main(){
	register int i,j;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),t[a[i]]++,minn=min(minn,a[i]),maxn=max(maxn,a[i]);
	for(i=minn;i<=maxn+n;i++) t[i]+=t[i-1];
	for(i=minn;i<=maxn;i++){
		flag=0;
		for(j=i;j<=i+n-1;j++){
			if((t[j]-j+i)%p==0){flag=1;break;}
		}
		if(!flag) ans[++head]=i;
	}
	printf("%d\n",head);
	for(i=1;i<=head;i++) printf("%d ",ans[i]);
}