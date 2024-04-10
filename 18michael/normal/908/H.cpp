#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;
int n,t=0,Mx;
int rt[52],to[52];
int f[8388608],g[8388608],one[8388608];
bool u[52][52];
char s[52][52];
vector<int> vec[52];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline bool check()
{
	int res=0;
	for(int i=0;i<=Mx;++i)res+=((one[i]^one[Mx])&1? -1:1)*f[i];
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)rt[i]=i;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;++j)if(s[i][j]=='A')getroot(i),getroot(j),rt[rt[i]]=rt[j];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(s[i][j]=='X')
			{
				getroot(i),getroot(j);
				if(rt[i]==rt[j])return 0&puts("-1");
			}
	for(int i=1;i<=n;++i)getroot(i),vec[rt[i]].push_back(i);
	for(int i=1;i<=n;++i)if(rt[i]==i && vec[i].size()>1)to[t++]=i;
	if(!t)return 0&printf("%d",n-1);
	for(int i=0;i<t;++i)for(int j=0;j<t;++j)for(int k=0;k<vec[to[i]].size();++k)for(int l=0;l<vec[to[j]].size();++l)u[i][j]|=(s[vec[to[i]][k]][vec[to[j]][l]]=='X');
	Mx=(1<<t)-1;
	for(int i=0,i0,i1;i<=Mx;++i)
	{
		one[i]=one[i>>1]+(i&1);
		if(!(i1=(i^(i0=lowbit(i)))))
		{
			f[i]=1;
			continue;
		}
		if(!f[i0] || !f[i1])continue;
		i0=log2(i0)+eps,f[i]=1;
		for(int j=0;j<t;++j)
			if(((i1>>j)&1) && u[j][i0])
			{
				f[i]=0;
				break;
			}
	}
	for(int i=1;i<=Mx;i<<=1)for(int j=0;j<=Mx;j+=(i<<1))for(int k=0;k<i;++k)f[i+j+k]+=f[j+k];
	for(int i=0;i<=Mx;++i)g[i]=f[i];
	for(int i=0;;++i)
	{
		if(check())return 0&printf("%d",n+i);
		for(int j=0;j<=Mx;++j)f[j]*=g[j];
	}
	return 0;
}