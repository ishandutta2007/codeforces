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
const int N=400;
int a[35][N][N][8],n,l[N],b[N][N],ax[]={-1,-1,0,1,1,1,0,-1},ay[]={0,1,1,1,0,-1,-1,-1},ans;
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(l[i]);
	l[1]--;
	a[0][200][200][0]=b[200][200]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=0;j<400;j++)
			for(int k=0;k<400;k++)
				for(int p=0;p<8;p++)if(a[i-1][j][k][p])
				{
					int x=(p+7)%8,y=(p+1)%8,xx=j,yy=k;
					b[xx][yy]=1;
					for(int q=1;q<=l[i];q++)xx+=ax[p],yy+=ay[p],b[xx][yy]=1;
					a[i][xx][yy][x]=a[i][xx][yy][y]=1;
				}
	for(int i=0;i<400;i++)
		for(int j=0;j<400;j++)if(b[i][j])ans++;
	write(ans);
	return 0;
}