#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
int n;
int l[111111],r[111111];
void exec()
{
	scanf("%d",&n);
	register int i;
	int lp=-1,rp=1e9+1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		if(r[i]<rp)rp=r[i];
		if(l[i]>lp)lp=l[i];
	}if(lp-rp<0)puts("0");
	else printf("%d\n",lp-rp);;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}