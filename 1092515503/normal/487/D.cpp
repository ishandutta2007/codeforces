#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
int n,m,q,BBB,BLK[100100];
pair<int,int>p[100100][12];
char s[100100][12];
bool vis[100100][12];
void func(int x){
	for(int i=1;i<=m;i++)p[x][i]=mp(0,0);
	for(int i=1;i<=m;i++){
		if(s[x][i]=='<')p[x][i]=mp(x,0);
		else break;
	}
	for(int i=m;i;i--){
		if(s[x][i]=='>')p[x][i]=mp(x,m+1);
		else break;
	}
	for(int i=1;i<=m;i++){
		if(s[x][i]!='^')continue;
		if(BLK[x-1]!=BLK[x])p[x][i]=mp(x-1,i);
		else p[x][i]=p[x-1][i];
		for(int j=i-1;j;j--){
			if(s[x][j]=='>')p[x][j]=p[x][i];
			else break;
		}
		for(int j=i+1;j<=m;j++){
			if(s[x][j]=='<')p[x][j]=p[x][i];
			else break;
		}
	}
	for(int i=1;i<=m;i++)if(p[x][i]==mp(0,0))p[x][i]=mp(-1,-1);
}
pair<int,int> ask(int x,int y){
	if(x==0||y==0||y==m+1)return make_pair(x,y);
	if(x==-1&&y==-1)return make_pair(-1,-1);
	return ask(p[x][y].x,p[x][y].y);
}
int main(){
	scanf("%d%d%d",&n,&m,&q),BBB=sqrt(n/(m*m)),BBB=max(BBB,1);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1),BLK[i]=(i-1)/BBB+1;
	for(int i=1;i<=n;i++)func(i);
	for(int i=1,x,y;i<=q;i++){
		char str[5];
		scanf("%s%d%d",str,&x,&y);
		if(str[0]=='A'){
			pair<int,int>res=ask(x,y);
			printf("%d %d\n",res.x,res.y);
		}else{
			scanf("%s",str);
			s[x][y]=str[0];
			for(int j=x;j<=n;j++)if(BLK[j]==BLK[x])func(j);else break;
		}
	}
	return 0;
}