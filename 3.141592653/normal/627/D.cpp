#include<bits/stdc++.h>
bool g[1111111],val;
int w[1111111],n,k;
std::vector<int>v[1111111];
int f[1111111],sz[1111111],fir[1111111],sec[1111111];
void dfs(int p=1,int f=0)
{
	if(g[p])::f[p]=1;sz[p]=1;
	for(int t:v[p])if(t^f)
	{
		dfs(t,p),sz[p]+=sz[t];
		if(sz[t]==::f[t])::f[p]+=::f[t];
		else
		{
			if(fir[p]<::f[t])sec[p]=fir[p],fir[p]=::f[t];
			else if(sec[p]<::f[t])sec[p]=::f[t];
		}
	}::f[p]+=fir[p];
	if(!g[p])::f[p]=0;
}
void solve(int p=1,int f=0,int vf=0)
{
	if(!g[f])vf=0;
	int rmsiz=n-sz[p];
	int r0=::f[p]-fir[p];
	if(vf==rmsiz)r0+=vf;
	else
	{
		if(fir[p]<vf)sec[p]=fir[p],fir[p]=vf;
		else if(sec[p]<vf)sec[p]=vf;
	}if(g[p])if(r0+fir[p]>=k)val=1;
	for(int t:v[p])if(t^f)
	{
		if(::f[t]==sz[t])solve(t,p,::f[p]-::f[t]);
		else if(::f[t]==fir[p])solve(t,p,r0+sec[p]);
		else solve(t,p,r0+fir[p]);
	}
}
bool valid(int Md)
{
	val=0;
	for(register int i=1;i<=n;i++)g[i]=(w[i]>=Md),f[i]=fir[i]=sec[i]=0;
	dfs(),solve();
	return val;
}
int main()
{
	register int i;
	for(i=1,scanf("%d%d",&n,&k);i<=n;i++)scanf("%d",w+i);
	for(i=2;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	}int L=0,R=1e6+5;
	while(L+1<R)
	{
		int M=(L+R)>>1;
		if(valid(M))L=M;
		else R=M;
	}printf("%d\n",L);
}
/*
Please don't let me down.
*/