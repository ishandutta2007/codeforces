#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,mod,ans=0,cnt=0;
LL res;
int rt[10202],to[10202],to_t[2],id[202];
int M[202][202];
char s[102][102];
inline int num(int x,int y)
{
	return x*(m+1)+y;
}
inline void getroot(int x)
{
	if(rt[x]==x)return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void work(int &x,int &y,int z,bool o)
{
	for(LL r;M[y][z];swap(x,y),res=-res)
	{
		r=M[x][z]/M[y][z];
		for(int i=z;i<to_t[o];++i)M[x][i]=(M[x][i]-r*M[y][i])%mod;
	}
}
inline void solve(bool o)
{
	if(to_t[o]>cnt+1)return ;
	for(int i=1;i<=to_t[o];id[i]=i,++i)for(int j=1;j<=to_t[o];++j)M[i][j]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='*')
			{
				--M[to[rt[num(i-1+((i^j^o)&1),j-1)]]][to[rt[num(i-((i^j^o)&1),j)]]];
				--M[to[rt[num(i-((i^j^o)&1),j)]]][to[rt[num(i-1+((i^j^o)&1),j-1)]]];
				++M[to[rt[num(i-1+((i^j^o)&1),j-1)]]][to[rt[num(i-1+((i^j^o)&1),j-1)]]];
				++M[to[rt[num(i-((i^j^o)&1),j)]]][to[rt[num(i-((i^j^o)&1),j)]]];
			}
	for(int i=res=1;i<to_t[o];++i)for(int j=i+1;j<to_t[o];++j)work(id[i],id[j],i,o);
	for(int i=1;i<to_t[o];++i)(res*=M[id[i]][i])%=mod;
	(ans+=res)%=mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=0;i<(n+1)*(m+1);++i)rt[i]=i;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='/')
			{
				getroot(num(i,j-1)),getroot(num(i-1,j));
				if(rt[num(i,j-1)]==rt[num(i-1,j)])return 0&puts("0");
				rt[rt[num(i,j-1)]]=rt[num(i-1,j)];
			}
			else if(s[i][j]=='\\')
			{
				getroot(num(i-1,j-1)),getroot(num(i,j));
				if(rt[num(i-1,j-1)]==rt[num(i,j)])return 0&puts("0");
				rt[rt[num(i-1,j-1)]]=rt[num(i,j)];
			}
			else ++cnt;
		}
	}
	for(int i=0;i<(n+1)*(m+1);++i)if((getroot(i),rt[i])==i)to[i]=(++to_t[((i/(m+1))^(i%(m+1)))&1]);
	solve(0),solve(1),printf("%d",(ans+mod)%mod);
	return 0;
}