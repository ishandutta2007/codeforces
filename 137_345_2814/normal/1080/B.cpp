#include<cstdio>
using namespace std;
int n,l,r;
int sol(int s)
{
	if(s&1)
	return -s+s/2;
	return s/2;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",sol(r)-sol(l-1));
	}
}