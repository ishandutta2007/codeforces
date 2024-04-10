#include<cstdio>
int main()
{
	int n,m;
	int cnt=0;
	scanf("%d%d",&n,&m);
	while(true)
	{
		if(n>=1 && m>=2 && m>=n)
		{
			n-=1;
			m-=2;
			cnt++;
			continue;
		}
		if(m>=1 && n>=2)
		{
			m-=1;
			n-=2;
			cnt++;
			continue;
		}
		break;
	}
	printf("%d",cnt);
}