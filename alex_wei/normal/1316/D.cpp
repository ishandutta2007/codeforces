#include<bits/stdc++.h>
using namespace std;
#define ill puts("INVALID"),exit(0) 
#define ll long long
const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int n,X[1005][1005],Y[1005][1005],pd[1005][1005];
char ans[1005][1005];
int dfsv(int x,int y,int dir){
	pd[x][y]=1;
	if(dir==0)ans[x][y]='D';
	if(dir==1)ans[x][y]='R';
	if(dir==2)ans[x][y]='L';
	if(dir==3)ans[x][y]='U';
	int sz=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(X[xx][yy]==-1&&!pd[xx][yy])sz+=dfsv(xx,yy,i);
	}
	return sz;
}
void dfsvv(int x,int y,int xxx,int yyy,int dir){
	pd[x][y]=1;
	if(xxx!=x||yyy!=y){
		if(dir==0)ans[x][y]='D';
		if(dir==1)ans[x][y]='R';
		if(dir==2)ans[x][y]='L';
		if(dir==3)ans[x][y]='U';
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(X[xx][yy]==xxx&&Y[xx][yy]==yyy&&!pd[xx][yy])dfsvv(xx,yy,xxx,yyy,i);
	}
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		scanf("%d%d",&X[i][j],&Y[i][j]);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(X[i][j]==-1&&!pd[i][j]){
			if(dfsv(i,j,0)==1)ill;
			int dir;
			for(int z=0;z<4;z++){
				int xx=i+dx[z],yy=j+dy[z];
				if(X[xx][yy]==-1){
					dir=z;
					break;
				}
			}
			if(dir==0)ans[i][j]='U';
			if(dir==1)ans[i][j]='L';
			if(dir==2)ans[i][j]='R';
			if(dir==3)ans[i][j]='D';
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(X[i][j]==i&&Y[i][j]==j){
			ans[i][j]='X';
			dfsvv(i,j,i,j,0);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!pd[i][j])ill;
	puts("VALID");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<ans[i][j];
		puts("");
	}
	return 0;
}