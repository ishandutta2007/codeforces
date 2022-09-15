#include<cstdio>
#include<cstring>
char buf[212121];
int cnt[212121];
int main()
{
	scanf("%s",buf);
	int M;
	scanf("%d",&M);
	int L=strlen(buf);
	for(int i=0;i<M;i++)
	{
		int t;
		scanf("%d",&t);
		cnt[t-1]++;
	}
	int par=0;
	for(int i=0;i<L/2;i++)
	{
		par+=cnt[i];
		if(par%2)buf[i]^=buf[L-i-1]^=buf[i]^=buf[L-i-1];
	}
	puts(buf);
	return 0;
}