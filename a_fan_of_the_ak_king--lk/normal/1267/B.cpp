#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int i,j,k;
char c[1000005];
struct str{
	int x;
	char c;
}p[500005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%s",c);
	for(i=0;c[i];)
	{
		for(j=i;c[i]==c[j]&&c[j];++j);
		p[++k]=(str){j-i,c[i]};
		i=j;
	}
	for(i=1;i<=k;++i)
		if(p[i].c!=p[k-i+1].c)
		{
			puts("0");
			return 0;
		}
	for(i=1;i<=k/2;++i)
		if(p[i].x+p[k-i+1].x<3)
		{
			puts("0");
			return 0;
		}
	if(p[k/2+1].x<2)
		puts("0");
	else
		printf("%d",p[k/2+1].x+1);
}