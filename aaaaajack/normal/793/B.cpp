#include<bits/stdc++.h>
#define N 1100
#define Q 998244353
using namespace std;
char s[N][N];
int dis[N][N][5];
int mx[4]={-1,0,1,0},my[4]={0,-1,0,1};
bool ix[N],iy[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	bool ans=false;
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				dis[i][j][4]=0;
				q.push(i*m*5+j*5+4);
			}
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int x=u/5/m,y=u/5%m,z=u%5;
		for(int d=0;d<4;d++){
			int nx=x+mx[d],ny=y+my[d];
			if(nx>=n||nx<0 || ny>=m || ny<0) continue;
			if(s[nx][ny]=='*') continue;
			if(dis[nx][ny][d]<0){
				dis[nx][ny][d]=dis[x][y][z]+(z!=d);
				q.push(nx*m*5+ny*5+d);
			}else if(dis[x][y][z]+(z!=d)<dis[nx][ny][d]){
				dis[nx][ny][d]=dis[x][y][z]+(z!=d);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='T'){
				for(int k=0;k<4;k++){
					if(dis[i][j][k]>=0&&dis[i][j][k]<=3) ans=true;
				}
			}
		}
	}
	if(ans) puts("YES");
	else puts("NO");
	return 0;
}