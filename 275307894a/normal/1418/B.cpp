#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,flag[1039],a[10039],b[1039],head,t;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) {scanf("%d",&b[i]);if(!b[i])flag[++head]=a[i];}
		sort(flag+1,flag+head+1);
		for(i=1;i<=n;i++){
			if(!b[i]) a[i]=flag[head--];
			printf("%d ",a[i]);
		}
		head=0;printf("\n");
	}
}