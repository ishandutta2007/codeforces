#include<cstdio>
#include<cmath>
using namespace std;
int n,t,m,ans,tot,a[100039],head,k,flag,f[100039];
int main(){
	register int i,j;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d",&n);
		m=sqrt(n);
		for(i=2;i<=m;i++){
			if(n%i==0){
				ans=n/i;
				k=sqrt(ans);
				for(j=2;j<=k;j++) {
					if(ans%j==0&&j!=i&&ans/j!=j&&ans/j!=i){
						printf("YES\n%d %d %d\n",i,j,ans/j);
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
		}
		if(!flag) printf("NO\n");
	}
}