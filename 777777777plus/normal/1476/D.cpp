#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int T;
int n;
int totw;
char s[N];
int f[N][2][2];
bool vis[N][2][2];

int dfs(int x,bool dir,bool t){
	if(vis[x][dir][t]==totw)return f[x][dir][t];
	int ret;
	if(dir==0){
		if(x==1)ret=1;
		else if(s[x-1]==t)ret=dfs(x-1,dir,t^1)+1;
		else ret=1;
	}
	else{
		if(x==n+1)ret=1;
		else if(s[x]!=t)ret=dfs(x+1,dir,t^1)+1;
		else ret=1;
	}
	vis[x][dir][t]=totw;
	return f[x][dir][t]=ret;
}

int main(){
	T=read();
	while(T--){
		++totw;
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)s[i]=(s[i]=='R');
		for(int i=1;i<=n+1;++i)printf("%d ",dfs(i,0,0)+dfs(i,1,0)-1);
		printf("\n");
	}
}