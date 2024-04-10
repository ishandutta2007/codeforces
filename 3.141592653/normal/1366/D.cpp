#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int a[1111111],b[1111111];
int n;
int fr[11111111];
void solve(int x,int o)
{
	int t=fr[x];
	if(!t){a[o]=b[o]=-1;return;}
	while(x%t==0)x/=t;
	if(x==1)a[o]=b[o]=-1;
	else a[o]=t,b[o]=x;
}
int main()
{
	int n;
	scanf("%d",&n);
	register int i,ii;
	for(i=1e7;i^1;i--)
		for(ii=i;ii<=1e7;ii+=i)
			fr[ii]=i;
	int x;
	for(i=1;i<=n;i++)scanf("%d",&x),solve(x,i);
	for(i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	for(i=1;i<=n;i++)printf("%d ",b[i]);puts("");
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/