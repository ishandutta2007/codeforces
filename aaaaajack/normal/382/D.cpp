#include<bits/stdc++.h>
#define N 2010
using namespace std;
char s[N][N];
int vis[N][N];
int to[N][N];
int val[N][N];
int solve(int i,int j,int c){
	if(s[i][j]=='#'){
		return 0;
	}
	vis[i][j]=c;
	int ti=i,tj=j;
	if(s[i][j]=='>') tj++;
	else if(s[i][j]=='<') tj--;
	else if(s[i][j]=='^') ti--;
	else ti++;
	if(vis[ti][tj]){
		if(vis[ti][tj]==c){
			val[i][j]=-1;
		}
		else if(val[ti][tj]==-1){
			val[i][j]=-1;
		}
		else{
			val[i][j]=val[ti][tj]+1;
		}
	}
	else{
		int tmp=solve(ti,tj,c);
		if(tmp==-1) val[i][j]=-1;
		else val[i][j]=tmp+1;
	}
	if(val[i][j]==1) to[i][j]=i*N+j;
	else to[i][j]=to[ti][tj];
	return val[i][j];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int c=0,mx=0,cur=0,diff=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]){
				solve(i,j,++c);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(val[i][j]==-1) mx=-1;
			else if(mx>=0&&val[i][j]>mx){
				mx=val[i][j];
				cur=to[i][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(val[i][j]==mx && to[i][j]!=cur) diff=0;
		}
	}
	if(mx==0||mx==-1) printf("%d\n",mx);
	else printf("%d\n",mx*2-diff);
	return 0;
}