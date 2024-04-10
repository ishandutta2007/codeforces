#include<cstdio>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cstring>
using namespace std;
const int MAX=13;
char ss[220];
struct node
{
	char L[50],R[50];int len;
	bitset<8200>b[MAX+1];
	void read()
	{
		scanf("%s",ss+1);len=strlen(ss+1);
		for (int u=1;u<=MAX;u++) b[u].reset();
		for (int u=1;u<=len;u++)
		{
			int s=0;//hash 
			for (int i=1;i<MAX&&(u+i-1<=len);i++)
			{
				s=s*2+(ss[u+i-1]-'0');
				b[i].set(s);
			}
		}
		for (int u=1;u<=MAX;u++) L[u]=ss[u];
		for (int u=1;u<=MAX;u++) R[u]=ss[len-u+1];
		len=min(len,MAX);
	}
	friend node operator + (node x,node y)
	{
		node z;
		z.len=min(x.len+y.len,MAX);
		for (int u=1;u<=MAX;u++) z.b[u]=x.b[u]|y.b[u];
		int l=0;for (int u=x.len;u>=1;u--) ss[++l]=x.R[u];
		for (int u=1;u<=y.len;u++) ss[++l]=y.L[u];
		for (int u=1;u<=l;u++)
		{
			int s=0;
			for (int i=1;i<=MAX&&(u+i-1<=l);i++)
			{
				s=s*2+(ss[u+i-1]-'0');
				z.b[i].set(s);
			}
		}
		for (int u=1;u<=x.len;u++) z.L[u]=x.L[u];
		for (int u=1;u<=y.len;u++) z.L[u+x.len]=y.L[u];
		for (int u=1;u<=y.len;u++) z.R[u]=y.R[u];
		for (int u=1;u<=x.len;u++) z.R[u+y.len]=x.R[u];
		return z;
	}
	int pre ()
	{
		for (int u=MAX;u>=1;u--)
			if (b[u].count()>=(1<<u)) 
				return u;
	}
}str[210];
int n,m;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
		str[u].read();
	scanf("%d",&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		str[u+n]=str[x]+str[y];
		printf("%d\n",str[u+n].pre());
	}
	return 0;
}