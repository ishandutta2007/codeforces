#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005,mod=1e9+7;
int fl[N],la[N],V[N],dp[N],c[N],pr[N],to[N],pdu,pdv,cnt=1,m,n,u,v,ans0,ans1,vis[N],f[N][2][2],del,x,y;
inline void ins(int x,int y,int z)
{
	to[++cnt]=y;
	pr[cnt]=la[x];
	la[x]=cnt;
	V[cnt]=z;
}
inline void add(int x,int y,int v1,int v2)
{
	x=abs(x);
	y=abs(y);
	ins(x,y,v1);
	ins(y,x,v2);
}
int check(int x,int y,int z)
{
	if (!(z&2))
		x^=1;
	if (!(z&1))
		y^=1;
	return x|y;
}
void dfs(int x,int fr)
{
	vis[x]=1;
	for (int i=la[x];i;i=pr[i])
	{
		if (!vis[to[i]])
			dfs(to[i],i);
		else
			if (i!=(fr^1))
			{
				u=x;
				v=to[i];
				del=i;
			}
	}
}
void tdp(int x,int fa)
{
	for (int i=la[x];i;i=pr[i])
		if (to[i]!=fa&&(i^del)&&(i^del^1))
			tdp(to[i],x);
	memset(f[x],0,sizeof(f[x]));
	for (int w=0;w<2;++w)
	{
		if (x==u&&w!=pdu)
			continue;
		if (x==v&&w!=pdv)
			continue;
		int ans0=1,ans1=0;
		for (int i=la[x];i;i=pr[i])
		{
			if (to[i]==fa||!(i^del)||!(i^del^1))
				continue;
			int an0=ans0,an1=ans1;
			ans0=0;
			ans1=0;
			for (int w1=0;w1<2;++w1)
			{
				int A=f[to[i]][w1][0],B=f[to[i]][w1][1];
				if (check(w,w1,V[i]))
					swap(A,B);
				ans0=(ans0+(ll)A*an0+(ll)B*an1)%mod;
				ans1=(ans1+(ll)A*an1+(ll)B*an0)%mod;
			}
		} 
		if (fl[x]&(1<<w))
			swap(ans0,ans1);
		f[x][w][0]=(f[x][w][0]+ans0)%mod;
		f[x][w][1]=(f[x][w][1]+ans1)%mod; 
	}
	//printf("%d %d %d %d %d %d\n",x,fa,f[x][0][0],f[x][1][0],f[x][0][1],f[x][1][1]);
}
void work(int x)
{
	cnt=0;
	del=-2;
	dfs(x,-1);
	int an0=0,an1=0;
	if (del==-2)
	{
		v=0;
		u=x;
		pdu=0;
		pdv=1;
		tdp(x,0);
		an0=(an0+(ll)f[x][0][0]+f[x][1][0])%mod;
		an1=(an1+(ll)f[x][0][1]+f[x][1][1])%mod;
		pdu=1;
		tdp(x,0);
		an0=(an0+(ll)f[x][0][0]+f[x][1][0])%mod;
		an1=(an1+(ll)f[x][0][1]+f[x][1][1])%mod;
	}
	else
	{
		for (pdu=0;pdu<2;++pdu)
			for (pdv=0;pdv<2;++pdv)
			{
				tdp(u,0);
				if (check(pdu,pdv,V[del]))
				{
					swap(f[u][0][0],f[u][0][1]);
					swap(f[u][1][0],f[u][1][1]);
				}
				an0=(an0+(ll)f[u][0][0]+f[u][1][0])%mod;
				an1=(an1+(ll)f[u][0][1]+f[u][1][1])%mod;
			}
	}
	//printf("%d %d\n",an0,an1);
	int k0=ans0,k1=ans1;
	ans0=((ll)an0*k0+(ll)an1*k1)%mod;
	ans1=((ll)an0*k1+(ll)an1*k0)%mod;
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		if (x==1)
		{
			scanf("%d",&y);
			if (y>0)
				fl[y]|=2;
			else
				fl[-y]|=1;
		} 
		else
		{
			scanf("%d%d",&x,&y);
			if (x<0)
			{
				if (y<0)
					add(x,y,0,0);
				else
					add(x,y,1,2);
			}
			else
			{
				if (y<0)
					add(x,y,2,1);
				else
					add(x,y,3,3);
			}
		}
	}
	ans0=1;
	ans1=0;
	for (int i=1;i<=n;++i)
		if (!vis[i])
			work(i);
	cout<<ans1;
}