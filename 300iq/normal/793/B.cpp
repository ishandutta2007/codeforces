#include <bits/stdc++.h>
using namespace std;
string s[1000];
bool vis[1000][1000][4][4];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,sx,sy;
bool is_turn(int px,int py,int tx,int ty){
	if(abs(px-tx)==1&&abs(py-ty)==1)
		return true;
	return false;
}
bool is_valid(int x,int y,int i, int t){
	if(x==n||y==m||y<0||x<0)
		return false;
	if((s[x][y]=='.'||s[x][y]=='T')&&!vis[x][y][i][t])
		return true;
	return false;
}
bool dfs(int px,int py,int x,int y,int t,int in){
	if(t>2){
		return false;
	}
	if(s[x][y]=='T')
		return true;
	vis[x][y][in][t]=true;
	bool tr=false;
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(is_valid(tx,ty,i, t)){
			if(is_turn(px,py,tx,ty))
			tr|=dfs(x,y,tx,ty,t+1,i);
		    else
		    	tr|=dfs(x,y,tx,ty,t,i);
		}
	}
	return tr;
}
int main(){
    scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int k=0;k<4;k++) for (int t = 0; t < 4; t++) vis[i][j][k][t] =false;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='S'){sx=i;sy=j;}
	bool res=false;
	for(int i=0;i<4;i++){
		if(is_valid(sx+dx[i],sy+dy[i],i, 0)) res|=dfs(sx,sy,sx+dx[i],sy+dy[i],0,i);
	}
	if(res)
		puts("YES");
	else
		puts("NO");

	return 0;
}