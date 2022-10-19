#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[100039],tot;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		tot=1;
		for(i=2;i<=n;i++) if(a[i]!=a[i-1]) tot++;
		printf("%d\n",tot);
	}
}