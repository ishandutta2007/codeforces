#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,k,ans,tot,pus,a[500039],f[500039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		ans=0;tot=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]),f[a[i]]++;
		for(i=1;i<=n;i++){
			tot+=f[i];ans+=tot/i;tot%=i;f[i]=0;
		}
		printf("%d\n",ans);
	}
}