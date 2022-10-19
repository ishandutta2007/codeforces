#include<cstdio>
using namespace std;
int n,m,k,x,y,z,g[1039],id[100039],q[539][100039],f[100039],head,a[100039],ans;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<=n) f[a[i]]++;
	}
	for(i=1;i<=n;i++)if(f[i]>=i) g[++head]=i,id[i]=head;
	for(i=1;i<=n;i++)if(a[i]<=n&&id[a[i]]) q[id[a[i]]][i]++;
	for(i=1;i<=head;i++){
		for(j=1;j<=n;j++) q[i][j]+=q[i][j-1];
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);ans=0;
		for(j=1;j<=head;j++)if(q[j][y]-q[j][x-1]==g[j]) ans++;
		printf("%d\n",ans);
	}
}