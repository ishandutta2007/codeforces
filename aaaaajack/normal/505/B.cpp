#include<bits/stdc++.h>
using namespace std;
int f[110][110];
int find(int x,int u){
	if(f[x][u]==u) return u;
	return f[x][u]=find(x,f[x][u]);
}
void uni(int z,int x,int y){
	int fx=find(z,x),fy=find(z,y);
	if(fx!=fy) f[z][fx]=fy;
}
int main(){
	int n,m,x,y,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) f[i][j]=j;
	for(int j=0;j<m;j++){
		scanf("%d%d%d",&x,&y,&c);
		uni(c,x,y);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		int ans=0;
		for(int i=1;i<=m;i++) if(find(i,x)==find(i,y)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}