#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
const int B=450;
int bel[N],L[N],R[N],c[N],d[N];
int n,m;
void Init (int n)
{
	bel[0]=1;for (int u=1;u<=n;u++) bel[u]=bel[u-1]+(u%B==0);
	for (int u=1;u<=n;u++) R[bel[u]]=u;
	for (int u=n;u>=1;u--) L[bel[u]]=u;
}
void add (int x,int y){if (x>m) return ;c[bel[x]]+=y;d[x]+=y;}
int query (int x)
{
	int tot=0;
	for (int u=1;u<bel[x];u++) tot=tot+c[u];
	for (int u=L[bel[x]];u<=x;u++) tot=tot+d[u];
	return tot;
}

struct qq
{
	int x,y,op;
}a[N];
int id[N];
int f[B][B];
int main()
{
	Init(200005);
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)	
	{
		scanf("%d%d",&a[u].x,&a[u].y);
		if (a[u].x+a[u].y>=B) a[u].op=1;
		else a[u].op=0;
	}
	for (int u=1;u<=m;u++)
	{
		int k,op;
		scanf("%d%d",&op,&k);
		if (op==1)	
		{
			id[k]=u;
			if (a[k].op==1)
			{
				for (int i=u;i<=m;i=i+a[k].x+a[k].y)
				{
				//	printf("YES:%d %d\n",u,i);
					add(i+a[k].x,1);
					add(i+a[k].x+a[k].y,-1);
				}
			}
			else
			{
			//	printf("YES:%d\n",u);
				int t=a[k].x+a[k].y;
				for (int i=u+a[k].x;i<u+a[k].x+a[k].y;i++)	
				{
				//	printf("YES:%d %d\n",t,i);
					f[t][i%t]++;
				}
			}
		}
		else
		{
			if (a[k].op==1)
			{
				
				for (int i=id[k];i<=m;i=i+a[k].x+a[k].y)
				{
					//printf("del:%d %d\n",id[k],i);
					add(i+a[k].x,-1);
					add(i+a[k].x+a[k].y,+1);
				}
			}
			else
			{
				int t=a[k].x+a[k].y;
				for (int i=id[k]+a[k].x;i<id[k]+a[k].x+a[k].y;i++)	f[t][i%t]--;
			}
		}
		int ans=query(u);
		for (int i=1;i<B;i++) ans=ans+f[i][u%i];
		printf("%d\n",ans);
	}
	return 0;
}