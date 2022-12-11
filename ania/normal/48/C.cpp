#include<cstdio>
#include<algorithm>
using namespace std;

int t[1111];
int res;

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		res = max(res, t[i]*(n+1)/i);
	}
	int q = 0;
	for(int i = 1; i <= n; i++)
	{
		if((res+1)*i < (n+1)*(t[i]+1))
			q++;
	}
	if(q == n) printf("not unique\n");
	else printf("unique\n%d\n", res);
}