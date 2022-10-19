#include<cstdio>
using namespace std;
int n,m,a[1039],f[1039][1039],ans;
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	if(n>m){printf("YES\n");return 0;}
	for(i=1;i<=n;i++) scanf("%d",&a[i]),a[i]%=m;
	for(i=1;i<=n;i++){
		f[i][a[i]]=1;
		for(j=0;j<m;j++) if(f[i-1][j]) f[i][(j+a[i])%m]=f[i][j]=1;
	}
	if(f[n][0]) printf("YES\n");
	else printf("NO\n");
	return 0;
}