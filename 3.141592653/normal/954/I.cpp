#include<cstdio>
typedef unsigned long long ull;
const ull bas=283476131;
ull hash[222222],k[222222];
char str[222222],ttt[222222];
char ref[2222];
int best[222222];
inline ull gethash(int l,int r)
{return hash[r]-hash[l-1]*k[r-l+1];}
int a[11];
int cnt,l,ls;
inline void exec(int dep)
{
	int k=7-dep;
	register int i;
	for(i=1;i<=6;i++)ref[i+96]=a[i]+96;
	for(i=1;str[i];i++)
		hash[i]=hash[i-1]*bas+ref[str[i]];
	l=i-1;
	ull key=0;
	for(i=1;ttt[i];i++)
		(key*=bas)+=ref[ttt[i]];
	ls=i-1;
	for(i=1;i+ls-1<=l;i++)
		if(key==gethash(i,i+ls-1))
			if(best[i]>k)best[i]=k;
			
}
void dfs(int dep=1,int beg=1)
{
	if(beg>6)
	{exec(dep);return;}
	a[beg]=dep;
	int b[11];
	register int i,ii;
	for(i=1;i<=6;i++)b[i]=a[i];
	for(i=0;i<(1<<6);i++)
	{
		for(ii=1;ii<=beg;ii++)
			if(i&(1<<(ii-1)))goto T;
		for(ii=beg+1;ii<=6;ii++)
			if(i&(1<<(ii-1)))
				if(a[ii])goto T;
		for(ii=beg+1;ii<=6;ii++)
			if(i&(1<<(ii-1)))
				a[ii]=dep;
		for(ii=beg+1;ii<=7;ii++)
			if(!a[ii])break;
		dfs(dep+1,ii);
		for(ii=1;ii<=6;ii++)a[ii]=b[ii];
		T:;
	}
}
int main()
{
	scanf("%s%s",str+1,ttt+1);
	register int i;
	for(i=1;i<=125555;i++)best[i]=5;
	k[0]=1;
	for(i=1;i<=125555;i++)k[i]=k[i-1]*bas;
	dfs();
	for(i=1;i+ls-1<=l;i++)
		printf("%d%c",best[i],(l^(i+ls-1))?' ':'\n');
}