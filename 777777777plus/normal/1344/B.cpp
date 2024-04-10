#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n,m;
char s[N][N];
int fa[N*N];
int fx[4]={0,0,-1,1};
int fy[4]={-1,1,0,0};

int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	bool flag=0; 
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(s[i][j]=='#'){
		flag=1;
	}
	if(!flag){
		puts("0");
		return 0;
	}
	bool flag1=0,flag2=0;
	for(int i=1;i<=n;++i){
		int l=0,r=0;
		for(int j=1;j<=m;++j)
		if(s[i][j]=='#'){
			if(!l)l=j;
			r=j;
		}
		if(!l){
			flag1=1;
		}
		for(int j=l;j<=r;++j)
		if(s[i][j]=='.'){
			puts("-1");
			return 0;
		}
	}
	for(int j=1;j<=m;++j){
		int l=0,r=0;
		for(int i=1;i<=n;++i)
		if(s[i][j]=='#'){
			if(!l)l=i;
			r=i;
		}
		if(!l){
			flag2=1;
		}
		for(int i=l;i<=r;++i)
		if(s[i][j]=='.'){
			puts("-1");
			return 0;
		}
	}
	if(!flag1&&flag2){
		puts("-1");
		return 0;
	}
	if(!flag2&&flag1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n*m;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(s[i][j]=='#'){
		for(int k=0;k<4;++k){
			int x=i+fx[k],y=j+fy[k];
			if(x<1||x>n||y<1||y>m||s[x][y]=='.')continue;
			fa[gf((i-1)*m+j)]=gf((x-1)*m+y);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(s[i][j]=='#'&&gf((i-1)*m+j)==(i-1)*m+j)ans++;
	printf("%d\n",ans);
}