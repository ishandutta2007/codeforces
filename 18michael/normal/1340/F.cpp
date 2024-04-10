#include<bits/stdc++.h>
#define bs 19260817
#define bs2 19491001
#define mod2 998244353
#define LL long long
using namespace std;
int n,k,q,sq,s_t,s1_t;
int a[100002],bl[100002],st[322],ed[322],s[100002];
LL pw[322],pw2[322];
int len[2][322];
LL Hs[2][322][322],Hs2[2][322][322];
bool ok[100002];
struct aaa
{
	int x,l,r,o;
}s1[100002];
inline void maintain(int x)
{
	s_t=len[0][x]=len[1][x]=ok[x]=0;
	for(int i=st[x];i<=ed[x];++i)if(s_t && s[s_t]>0 && s[s_t]==-a[i])--s_t;else s[++s_t]=a[i];
	for(int i=1;i<s_t;++i)if(s[i]>0 && s[i+1]<0)return (void)(ok[x]=1);
	for(int i=1;i<=s_t;++i)
	{
		if(s[i]>0)
		{
			for(int j=s_t;j>=i;--j)++len[1][x],Hs[1][x][len[1][x]]=Hs[1][x][len[1][x]-1]*bs+s[j],Hs2[1][x][len[1][x]]=(Hs2[1][x][len[1][x]-1]*bs2+s[j])%mod2;
			break;
		}
		++len[0][x],Hs[0][x][len[0][x]]=Hs[0][x][len[0][x]-1]*bs-s[i],Hs2[0][x][len[0][x]]=(Hs2[0][x][len[0][x]-1]*bs-s[i])%mod2;
	}
}
inline LL getHs(int x,int l,int r,int o)
{
	return Hs[o][x][r]-Hs[o][x][l-1]*pw[r-l+1];
}
inline LL getHs2(int x,int l,int r,int o)
{
	return ((Hs2[o][x][r]-Hs2[o][x][l-1]*pw2[r-l+1])%mod2+mod2)%mod2;
}
inline bool ins(aaa a)
{
	for(;s1_t;--s1_t)
	{
		if(a.l>a.r)return 0;
		if(!s1[s1_t].o || a.o)return s1[++s1_t]=a,0;
		if(s1[s1_t].r-s1[s1_t].l>a.r-a.l)
		{
			if(getHs(s1[s1_t].x,s1[s1_t].l,s1[s1_t].l+a.r-a.l,1)^getHs(a.x,a.l,a.r,0) && getHs2(s1[s1_t].x,s1[s1_t].l,s1[s1_t].l+a.r-a.l,1)^getHs2(a.x,a.l,a.r,0))return 1;
			return s1[s1_t].l+=a.r-a.l+1,0;
		}
		if(getHs(s1[s1_t].x,s1[s1_t].l,s1[s1_t].r,1)^getHs(a.x,a.l,a.l+s1[s1_t].r-s1[s1_t].l,0) && getHs2(s1[s1_t].x,s1[s1_t].l,s1[s1_t].r,1)^getHs2(a.x,a.l,a.l+s1[s1_t].r-s1[s1_t].l,0))return 1;
		a.l+=s1[s1_t].r-s1[s1_t].l+1;
	}
	if(a.l<=a.r)s1[++s1_t]=a;
	return 0;
}
inline void solve(int x,int y)
{
	s_t=s1_t=0;
	if(bl[x]==bl[y])
	{
		for(int i=x;i<=y;++i)if(s_t && s[s_t]>0 && s[s_t]==-a[i])--s_t;else s[++s_t]=a[i];
		return (void)(puts(s_t? "No":"Yes"));
	}
	for(int i=x;i<=ed[bl[x]];++i)if(s_t && s[s_t]>0 && s[s_t]==-a[i])--s_t;else s[++s_t]=a[i];
	for(int i=1;i<=s_t;++i)
	{
		if(s[i]<0)return (void)(puts("No"));
		Hs[1][0][i]=Hs[1][0][i-1]*bs+s[s_t-i+1],Hs2[1][0][i]=(Hs2[1][0][i-1]*bs2+s[s_t-i+1])%mod2;
	}
	if(ins((aaa){0,1,s_t,1}))return (void)(puts("No"));
	for(int i=bl[x]+1;i<bl[y];++i)
	{
		if(ok[i])return (void)(puts("No"));
		if(ins((aaa){i,1,len[0][i],0}) || ins((aaa){i,1,len[1][i],1}))return (void)(puts("No"));
	}
	s_t=0;
	for(int i=st[bl[y]];i<=y;++i)if(s_t && s[s_t]>0 && s[s_t]==-a[i])--s_t;else s[++s_t]=a[i];
	for(int i=1;i<=s_t;++i)
	{
		if(s[i]>0)return (void)(puts("No"));
		Hs[0][0][i]=Hs[0][0][i-1]*bs-s[i],Hs2[0][0][i]=(Hs2[0][0][i-1]*bs2-s[i])%mod2;
	}
	if(ins((aaa){0,1,s_t,0}))return (void)(puts("No"));
	puts(s1_t? "No":"Yes");
}
int main()
{
	scanf("%d%d",&n,&k),sq=sqrt(n),pw[0]=pw2[0]=1;
	for(int i=1;i<=sq;++i)pw[i]=pw[i-1]*bs,pw2[i]=(pw2[i-1]*bs2)%mod2;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),bl[i]=(i-1)/sq+1;
	for(int i=1;i<=bl[n];++i)st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n),maintain(i);
	scanf("%d",&q);
	for(int o,x,y;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)a[x]=y,maintain(bl[x]);
		else solve(x,y);
	}
	return 0;
}