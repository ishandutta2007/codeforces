#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=105;
const int D=2005;
int n;
struct qq
{
	int t,d,p;
	int id;
}s[N];
int f[D];//
bool cmp (qq a,qq b){return a.d<b.d;}//d
int g[D][N];// 
int mymax (int x,int y){return x>y?x:y;}
int main()
{
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	
	{
		scanf("%d%d%d",&s[u].t,&s[u].d,&s[u].p);
		s[u].id=u;
	}
	sort(s+1,s+1+n,cmp);
	f[0]=0;
	int ans=0;
	for (int u=1;u<=n;u++)
	{
		for (int i=s[u].d-1;i>=s[u].t;i--)// 
		{
			if (f[i-s[u].t]+s[u].p>f[i])
			{
				f[i]=f[i-s[u].t]+s[u].p;
				for (int j=1;j<=g[i-s[u].t][0];j++)
					g[i][j]=g[i-s[u].t][j];
				g[i][0]=g[i-s[u].t][0]+1;
				g[i][g[i][0]]=s[u].id;
			}
			if (f[i]>f[ans]) ans=i;
		}
	}
	printf("%d\n%d\n",f[ans],g[ans][0]);
	for (int u=1;u<=g[ans][0];u++)
		printf("%d ",g[ans][u]);
	return 0;
}