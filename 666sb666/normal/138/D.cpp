#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int N=50;
int n,m,sg[N][N][N][N][2];
char s[N][N];
int dfs(int x0,int x2,int y0,int y2,int type)
{
	if(sg[x0][x2][y0][y2][type]>=0)return sg[x0][x2][y0][y2][type];
	int a[N*N];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)if(((i+j)&1)==type)
		{
			int x=i+j,y=i-j+m;
			if(x>=x0&&x<x2&&y>=y0&&y<y2)
			{
				int tmp=0;
				if(s[i][j]=='L')tmp=dfs(x0,x,y0,y2,type)^dfs(x+1,x2,y0,y2,type);
				if(s[i][j]=='R')tmp=dfs(x0,x2,y0,y,type)^dfs(x0,x2,y+1,y2,type);
				if(s[i][j]=='X')tmp=dfs(x0,x,y0,y,type)^dfs(x0,x,y+1,y2,type)^dfs(x+1,x2,y0,y,type)^dfs(x+1,x2,y+1,y2,type);
				a[tmp]=1;
			}
		}
	while(a[++sg[x0][x2][y0][y2][type]]);
	return sg[x0][x2][y0][y2][type];
}
int main()
{
	memset(sg,-1,sizeof(sg));
	read(n),read(m);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	if(dfs(0,n+m,0,n+m,0)^dfs(0,n+m,0,n+m,1))puts("WIN");else puts("LOSE");
	return 0;
}