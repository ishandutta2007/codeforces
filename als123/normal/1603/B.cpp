#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
void solve ()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if (a==b) printf("%d\n",a);
	if (a<b)
	{
		a/=2;b/=2;
		printf("%d\n",b+b-b%a);
	}
	if (a>b)
	{
		printf("%d\n",a+b);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--) solve();
	
	return 0;
}