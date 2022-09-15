#include<cstdio>
int dr[100100];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int u=1;
	int d=N;
	int n=1;
	for(int i=0;i<K-1;i++)
	{
		n=1-n;
		if(n) printf("%d ",d--);
		else printf("%d ",u++);
	}
	if(n==1) for(int i=u;i<=d;i++) printf("%d ",i);
	else for(int i=d;i>=u;i--) printf("%d ",i);
	return 0;
}