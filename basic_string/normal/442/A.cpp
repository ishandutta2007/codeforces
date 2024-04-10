#include<bits/stdc++.h>
using namespace std;
const int N=3009;
bool f[5][5],g[11];
int w[99],ans,t[11],d[5][5],p[5][5];
void dfs(int x,int y){
	if(y>=ans)return;
	if(x==10){
		int i,j;
		bool b=0;
		memset(d,0,sizeof(d)),memset(t,0,sizeof(t));
		for(i=0;i<5;++i)if(g[i]){
			for(j=0;j<5;++j)if(f[i][j])++t[i],d[i][j]=1,p[i][j]=i;
		}
		for(i=0;i<5;++i)if(g[i+5]){
			for(j=0;j<5;++j)if(f[j][i]){
				if(d[j][i])--t[p[j][i]];else ++t[p[j][i]=i+5];
				++d[j][i];
			}
		}
		for(i=0;i<5;++i)for(j=0;j<5;++j)if(f[i][j]){
			if(d[i][j]==0){
				if(b)return;
				b=1;
			}else if(d[i][j]==1&&t[p[i][j]]>1)if(t[p[i][j]]>1)return;
		}
		ans=y;
		return;
	}
	dfs(x+1,y),g[x]=1,dfs(x+1,y+1),g[x]=0;
}
int main(){
	int n;
	char u,v;
	w['R']=1,w['G']=2,w['W']=3,w['Y']=4,scanf("%d",&n);
	while(n--)scanf(" %c%c",&u,&v),f[w[u]][v-'1']=1;
	ans=8,dfs(0,0),printf("%d",ans);
	return 0;
}