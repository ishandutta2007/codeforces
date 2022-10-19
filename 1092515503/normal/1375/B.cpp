#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[310][310],b[310][310];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		bool ok=true;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			bool x=(i==1||i==n),y=(j==1||j==m);
			if(x&&y)b[i][j]=2;
			else if(x||y)b[i][j]=3;
			else b[i][j]=4;
			ok&=(b[i][j]>=a[i][j]);
		}
		if(!ok){puts("NO");continue;}
		puts("YES");
		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",b[i][j]);puts("");}
	}
	return 0;
}