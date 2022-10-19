#include<cstdio>
using namespace std;
int n,m,k,f[400039],sum[400039],x,y,ans[100039],a[100039],now,tot,flag;
long long pus;
inline int max(int a,int b){return a>b?a:b;} 
inline int min(int a,int b){return a<b?a:b;} 
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%d",&a[i]),pus+=a[i];
	if(pus<n){printf("-1");return 0;}
	if(m+a[n]-1>n){printf("-1");return 0;}
	for(i=1;i<=m;i++) if(n-a[i]+1<i){printf("-1\n");return 0;}
	now=n;
	for(i=m;i>=1;i--){
		if(now-a[i]+1<=i)break;
		ans[i]=now-a[i]+1;
		now-=a[i];
	}
	for(i=1;i<=m;i++){
		if(ans[i]) break;
		ans[i]=i;
	}
	for(i=1;i<=m;i++) printf("%d ",ans[i]);
}