#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
template<class T>inline void print(T x,int op=1){
	static int top,stk[105];
	if(x<0)x=-x,putchar('-');
	if(x==0)putchar('0');
	while(x)stk[++top]=x%10,x/=10;
	while(top)putchar(stk[top--]+'0');
	if(~op)putchar(" \n"[op]);
}
const int M=1005;
int n,m,k,A[M][M];
int fa[M*M],id[M][M],X[M*M],Y[M*M];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	rd(n),rd(m),rd(k);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)rd(A[i][j]);
	int tot=0;
	for(int i=1;i<=n+1;i++)for(int j=1;j<=m;j++){
		id[i][j]=++tot;
		fa[tot]=tot;
		X[tot]=i;
		Y[tot]=j;
	}
	for(int i=1;i<=k;i++){
		int x=1,y;
		rd(y);
		while(x!=n+1){
			int f=getfa(id[x][y]);
			x=X[f];
			y=Y[f];
			if(x<=n)fa[id[x][y]]=id[x+1][y];
			if(A[x][y]==1)A[x][y]=2,y++;
			else if(A[x][y]==2)x++;
			else if(A[x][y]==3)A[x][y]=2,y--;
		}
		printf("%d%c",y,i==k?'\n':' ');
	}
	return (0-0);
}