#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q,i,j,k;
char s[25][15],t[25][15];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%s",s[i]);
	for(i=1;i<=m;++i)
		scanf("%s",t[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&i);
		j=(i%n==0?n:i%n);
		k=(i%m==0?m:i%m);
		printf("%s%s\n",s[j],t[k]);
	}
	return 0;
}