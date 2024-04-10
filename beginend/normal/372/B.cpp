#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MIN(x,y) x=min(x,y)
#define MAX(x,y) x=max(x,y)
using namespace std;

const int N=45;

int n,m,a[N][N],q,f[N][N][N][N],ans,r[5],len[5];
char ch[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void get(int x,int w)
{
	if (x>4) {ans+=f[r[1]][r[2]][r[3]][r[4]]*w;return;}
	get(x+1,w);
	r[x]-=len[x];w=-w;
	get(x+1,w);
	r[x]+=len[x];
}

int main()
{
	n=read();m=read();q=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for (int j=1;j<=m;j++) a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+ch[j]-'0';
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=i;k<=n;k++)
				for (int l=j;l<=m;l++)
					if (a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1]==0)
						f[i][j][k][l]++;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=n;k++)
				for (int l=1;l<=m;l++)
				{
					r[1]=i;r[2]=j;r[3]=k;r[4]=l;
					len[1]=len[2]=len[3]=len[4]=1;
					ans=0;
					get(1,-1);
					f[i][j][k][l]=ans+f[i][j][k][l]*2;
				}
	while (q--)
	{
		int i=read(),j=read(),k=read(),l=read();
		ans=0;
		r[1]=r[3]=k;r[2]=r[4]=l;
		len[1]=len[3]=k-i+1;
		len[2]=len[4]=l-j+1;
		get(1,1);
		printf("%d\n",ans);
	}
	return 0;
}