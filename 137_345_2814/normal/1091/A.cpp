#include<cstdio>
using namespace std;
int mx=1e8,a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	b--;c-=2;
	if(mx>a)mx=a;
	if(mx>b)mx=b;
	if(mx>c)mx=c;
	printf("%d\n",mx*3+3);
}