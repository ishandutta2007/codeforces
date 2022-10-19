#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10039],ans,tot,pus,f[100039];
int main(){
	register int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		if(!f[i]){
			for(j=1;j<=n;j++) if(a[j]%a[i]==0&&!f[j]) f[j]=1;
			ans++;
		}
	}
	printf("%d",ans);
}