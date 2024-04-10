#include<cstdio>
using namespace std;
int a[110][110],w[110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		int u=-1;
		for(int j=1;j<=n;j++){
			if(u==-1||a[i][j]>a[i][u]) u=j;
		}
		w[u]++;
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		if(ans==-1||w[i]>w[ans]) ans=i;
	}
	printf("%d\n",ans);
	return 0;
}