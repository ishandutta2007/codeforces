#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,a[139],b[139],flag,tot;
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		sort(b+1,b+m+1);
		tot=b[1];
		for(i=2;i<=m;i++){
			if(b[i]-1!=b[i-1]){
				sort(a+tot,a+b[i-1]+2);
				//for(j=1;j<=n;j++) printf("%d ",a[j]);
				//printf("\n");
				tot=b[i];
			}
		}
		sort(a+tot,a+b[m]+2);
		for(i=2;i<=n;i++) if(a[i]<a[i-1]){flag=1;break;}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}