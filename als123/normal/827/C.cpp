#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
char ss[N]; 
int n;
int f[4][11][11][N];
int get (char x)
{
	if (x=='A') return 0;
	if (x=='T') return 1;
	if (x=='G') return 2;
	if (x=='C') return 3;
}
int lb (int x)	{return x&(-x);}
int modify (int x,int id,int c)
{
	for (int u=1;u<=10;u++)
	{
		int y=x%u,xx=x;
		while (xx<=n)
		{
			f[id][u][y][xx]=f[id][u][y][xx]+c;
			xx=xx+lb(xx);
		}
	}
}
int get (int u,int y,int id,int xx)
{
	int lalal=0;
	while (xx>=1)
	{
		lalal=lalal+f[id][u][y][xx];
		xx=xx-lb(xx);
	}
	return lalal;
}
char S[N];
int main()
{
	scanf("%s",ss+1);n=strlen(ss+1);
	for (int u=1;u<=n;u++)	modify(u,get(ss[u]),1);
	int q;scanf("%d",&q);
	while (q--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int x;
			scanf("%d%s",&x,S);
			modify(x,get(ss[x]),-1);
			ss[x]=S[0];
			modify(x,get(ss[x]),1);
		}
		else
		{
			int l,r;
			scanf("%d%d%s",&l,&r,S+1);
			int len=strlen(S+1),ans=0;
			for (int u=1;u<=len;u++)
			{
				int t=u+l-1;
				//printf("%d %d %d %d\n",r,get(S[u]),t%len,get(len,t%len,get(S[u]),r));
				//printf("%d\n",get(len,t%len,get(S[u]),r)-get(len,t%len,get(S[u]),l-1));
				ans=ans+get(len,t%len,get(S[u]),r)-get(len,t%len,get(S[u]),l-1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}