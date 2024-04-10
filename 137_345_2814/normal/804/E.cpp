#include<cstdio>
using namespace std;
#define N 1050
int n,is[N],fg;
void doit(int a,int b)
{
	if(a>b)a^=b^=a^=b;
	if(fg&&!is[a]&&!is[b])printf("%d %d\n%d %d\n%d %d\n",a,n,a,b,b,n),is[a]=is[b]=1;
	else printf("%d %d\n",a,b);
}
void doit1(int s){doit(s,s+1);doit(s+2,s+3);doit(s,s+3);doit(s+1,s+2);doit(s,s+2);doit(s+1,s+3);}
void doit2(int s,int t)
{
	for(int i=1;i<=4;i++)doit(s+i%4,t+i%4);
	for(int i=1;i<=4;i++)doit(s+i%4,t+(i+2)%4);
	for(int i=1;i<=4;i++)doit(s+i%4,t+(i+1)%4);
	for(int i=1;i<=4;i++)doit(s+i%4,t+(i+3)%4);
}
int main()
{
	scanf("%d",&n);
	if(n*(n-1)/2%2){printf("NO\n");return 0;}
	printf("YES\n");
	if(n&1)fg=1;
	for(int i=1;i<=n/4;i++)doit1(i*4-3);
	for(int i=1;i<=n/4;i++)for(int j=i+1;j<=n/4;j++)doit2(i*4-3,j*4-3);
}