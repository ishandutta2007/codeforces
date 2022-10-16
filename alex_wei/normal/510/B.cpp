#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int n,m,pd[55][55];
char s[55][55];
void dfs(int x,int y,int fx,int fy,char c){
	pd[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx==fx&&yy==fy||s[xx][yy]!=c)continue;
		if(pd[xx][yy])puts("Yes"),exit(0);
		if(xx&&yy&&xx<=n&&yy<=m)dfs(xx,yy,x,y,c);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!pd[i][j])
				dfs(i,j,0,0,s[i][j]);
	puts("No");
    return 0;
}