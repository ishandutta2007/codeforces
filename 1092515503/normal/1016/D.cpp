#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],g[110][110],A,B;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),A^=a[i];
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),B^=b[i];
	if(A!=B){puts("NO");return 0;}
	puts("YES");
	for(int i=1;i<=n;i++)g[i][1]^=a[i];
	for(int j=1;j<=m;j++)g[1][j]^=b[j];
	g[1][1]^=A;
	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",g[i][j]);puts("");}
	return 0;
}