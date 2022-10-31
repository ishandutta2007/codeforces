#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=5005;
int n,T,a[N],cn[N],o,ans[N];
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d",&n),memset(cn,0,sizeof(cn)),o=0;
		for(i=0;i<n;++i) scanf("%d",&a[i]),++cn[a[i]];
		while(1){
			for(i=1;i<n&&a[i]>=a[i-1];++i);
			if(i>n) break;
			for(i=0;cn[i]>0;++i);
			ans[++o]=j=i-(i>=n),n-=(i>=n),--cn[a[j]],++cn[i],a[j]=i;
		}
		//for(i=1;i<=n;++i) printf("%d ",a[i]);puts("");
		printf("%d\n",o);for(i=1;i<=o;++i) printf("%d ",ans[i]+1);puts("");
	}
	return 0;
}