#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
void exec()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int g=n/k;
	if(m<=g)printf("%d\n",m);
	else
	{
		int tipo=(m-g-1)/(k-1)+1;
		printf("%d\n",g-tipo);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/