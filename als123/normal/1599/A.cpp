#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int a[N];
int n;
char ss[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	sort(a+1,a+1+n);
	scanf("%s",ss+1);
	int x=0;
	for (int u=2;u<=n;u++) if (ss[u]!=ss[u-1]) x++;
	int L=n-x,R=L+1;
	int now=(ss[1]=='L');
	printf("%d %c\n",a[L],now==0?'R':'L');L--;
	for (int u=2;u<=n;u++)
	{
		if (ss[u]==ss[u-1])
		{
			now^=1;
			printf("%d %c\n",a[L--],now==0?'R':'L');
		}
		else 
		{
			printf("%d %c\n",a[R++],ss[u]);
		}
	}
	return 0;
}