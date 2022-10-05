#include<bits/stdc++.h>
using namespace std;
int a[37][37],n,m,ans=-1e9;
bool b[37][37];
#define g(x,y) (b[x][y]?-a[x][y]:a[x][y])
#define get(x,y) (g(x,y)+g(x+m,y)+g(x,y+m)+g(x+m,y+m))
void cov(int x,int y){
	b[x][y+m]=b[x][y]^b[x][m],b[x+m][y]=b[x][y]^b[m][y],b[x+m][y+m]=b[x+m][y]^b[x+m][m];
}
int calc(int x,bool y){
	int i,r=0,w;
	b[x][m]=y,b[x+m][m]=y^b[m][m];
	for(i=1;i<m;++i)b[x][i]=1,cov(x,i),w=get(x,i),b[x][i]=0,cov(x,i),r+=max(w,get(x,i));
	return r+g(x,m)+g(x+m,m);
}
void dfs(int x){
	if(x>m){
		int r=0,w,i,j;
		for(i=1;i<m;++i)b[m][m+i]=b[m][i]^b[m][m];
		for(i=1;i<m;++i)w=calc(i,1),r+=max(w,calc(i,0));
		for(i=1;i<=n;++i)r+=g(m,i);
		ans=max(ans,r);
		return;
	}
	b[m][x]=1,dfs(x+1),b[m][x]=0,dfs(x+1);
}
int main(){
	int i,j;
	cin>>n,m=n+1>>1;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)cin>>a[i][j];
	dfs(1),cout<<ans;
	return 0;
}