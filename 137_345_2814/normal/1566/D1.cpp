#include<cstdio>
using namespace std;
#define N 10500
int T,n,m,s[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d",&s[i]);
		int as=0;
		for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		if(s[j]>s[i])as++;
		printf("%d\n",as);
	}
}