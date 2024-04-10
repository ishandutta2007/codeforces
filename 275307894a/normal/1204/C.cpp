#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,f[239][239],a[1000039],tot,ans,pus,head;
char s;
int main() {
	memset(f,0x3f,sizeof(f));
	register int i,j,k;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			s=getchar();
			while(s<'0'||s>'9') s=getchar();
			if(s=='1')f[i][j]=s-'0';
		}
		f[i][i]=0;
	}
	for(k=1; k<=n; k++) {
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	scanf("%d",&m);
	for(i=1; i<=m; i++) scanf("%d",&a[i]);
	tot=a[1];
	for(i=2; i<m; i++) {
		//printf("%d %d %d\n",f[tot][a[i]],f[a[i]][a[i+1]],f[tot][a[i+1]]);
		if(f[tot][a[i]]+f[a[i]][a[i+1]]!=f[tot][a[i+1]]) ans++,tot=a[i];
	}
	printf("%d\n",ans+2);
	tot=a[1];
	printf("%d ",a[1]);
	for(i=2; i<m; i++) {
		if(f[tot][a[i]]+f[a[i]][a[i+1]]!=f[tot][a[i+1]]) printf("%d ",a[i]),tot=a[i];
	}
	if(m!=1)printf("%d\n",a[m]);
	return 0;
}