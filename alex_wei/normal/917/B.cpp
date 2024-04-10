#include<bits/stdc++.h>
using namespace std;
int n,m,SG[105][105][128][2];
char e[105][105];
int dfs(int x,int y,char k,bool fir){
	if(SG[x][y][k][fir]!=-1)return SG[x][y][k][fir];
	SG[x][y][k][fir]=0;
	if(fir)
		for(int i=1;i<=n;i++){
			if(e[x][i]&&e[x][i]>=k)
				SG[x][y][k][fir]|=!dfs(i,y,e[x][i],0);
		}
	else
		for(int i=1;i<=n;i++)
			if(e[y][i]&&e[y][i]>=k)
				SG[x][y][k][fir]|=!dfs(x,i,e[y][i],1);
	return SG[x][y][k][fir];
}
int main(){
	cin>>n>>m;
	memset(SG,-1,sizeof(SG));
	for(int i=1;i<=m;i++){
		int x,y;
		char t;
		cin>>x>>y>>t;
		e[x][y]=t;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dfs(i,j,0,1),cout<<(char)(!SG[i][j][0][1]+'A');
		cout<<endl;
	}
	return 0;
}