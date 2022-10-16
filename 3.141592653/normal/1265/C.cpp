#include<cstdio>
#include<cstring>
#include<algorithm>
int n;
int a[1111111];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		register int i;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		std::sort(a+1,a+n+1),a[0]=-1;
		int g=0,S=0,b=0;
		for(i=n;i;i--)
		{
			g++;
			if(a[i]!=a[i-1])break;
		}if(!g){puts("0 0 0");goto ED;}
		for(i--;i;i--)
		{
			while(a[i]==a[i-1])S++,i--;
			S++;
			if(S>g)break;
		}
		if(S<=g){puts("0 0 0");goto ED;}
		for(i--;i;i--)
		{
			int tmp=1;
			while(a[i]==a[i-1])tmp++,i--;
			if(g+S+b+tmp>(n>>1))break;
			b+=tmp;
		}if(b<=g){puts("0 0 0");goto ED;}
		if(g+S+b>(n>>1)){puts("0 0 0");goto ED;}
		printf("%d %d %d\n",g,S,b);
		ED:;
	}
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/