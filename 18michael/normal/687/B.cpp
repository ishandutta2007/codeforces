#include<cstdio>
int n,k,p_t=0;
bool ok=1;
int p[52],tim[52]={};
int c[1000002];
inline bool check(int x)
{
	int t;
	for(int i=1;i<=n;++i)
		if(!(c[i]%p[x]))
		{
			t=0;
			do ++t,c[i]/=p[x];while(!(c[i]%p[x]));
			if(t>=tim[x])return 1;
		}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=2;i*i<=k;++i)
		if(!(k%i))
		{
			p[++p_t]=i;
			do ++tim[p_t],k/=i;while(!(k%i));
		}
	if(k>1)p[++p_t]=k,tim[p_t]=1;
	for(int i=1;i<=p_t;++i)
		if(!check(i))
		{
			ok=0;
			break;
		}
	printf(ok? "Yes":"No");
	return 0;
}