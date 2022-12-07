#include<cstdio>
#include<cstring>
int n;
int ans[100];
bool check (int x)
{
	int lalal=x;
	while (x>0)
	{
		lalal=lalal+x%10;
		x/=10;
	}
	return lalal==n;
}
int mymax (int x,int y){return x>y?x:y;}
int main()
{
	scanf("%d",&n);
	for (int u=mymax(n-81,1);u<=n;u++)
		if (check(u)==true)
			ans[++ans[0]]=u;
	printf("%d\n",ans[0]);
	for (int u=1;u<=ans[0];u++) printf("%d\n",ans[u]);
	return 0;
}