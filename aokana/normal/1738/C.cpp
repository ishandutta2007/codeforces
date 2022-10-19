#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=110;
int a[maxn],f[maxn][maxn],g[maxn][maxn],m,n,t_case;
int dfs2(int,int);
int dfs1(int x,int y){
	if(~f[x][y])return f[x][y];
	if(x+y==1)return !x;
	ri z=0;
	if(x&1){
		z|=!dfs1(x-1,y);
		if(y)z|=!dfs1(x,y-1);
	}
	else{
		if(x)z|=!dfs2(x-1,y);
		if(y)z|=!dfs2(x,y-1);
	}
	return f[x][y]=z;
}
int dfs2(int x,int y){
	if(~g[x][y])return g[x][y];
	if(x+y==1)return !!x;
	ri z=0;
	if(x&1){
		z|=!dfs2(x-1,y);
		if(y)z|=!dfs2(x,y-1);
	}
	else{
		if(x)z|=!dfs1(x-1,y);
		if(y)z|=!dfs1(x,y-1);
	}
	return g[x][y]=z;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri x=0,y=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			++((a[i]&1)?x:y);
		}
		memset(f,-1,sizeof f),memset(g,-1,sizeof g);
		puts(dfs1(x,y)?"Alice":"Bob");
	}
	return 0;
}