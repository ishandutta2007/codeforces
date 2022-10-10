#include <cstdio>

const int MAXN=20*10086;
int n,q1[MAXN],q2[MAXN],x,y;
char a[MAXN],b[MAXN];
int main()
{
	register int i;
	
	scanf("%d%*c%s%s",&n,a+1,b+1);
	for(i=1;i<=n;i++)if(a[i]!=b[i])
	{
		if(a[i]<b[i])q1[++x]=i;
		else q2[++y]=i;
	}
	if(x+y&1)return puts("-1"),0;
	printf("%d\n",(x+y>>1)+(x&1));
	for(i=2;i<=x;i+=2)printf("%d %d\n",q1[i],q1[i-1]);
	for(i=2;i<=y;i+=2)printf("%d %d\n",q2[i],q2[i-1]);
	if(x&1)printf("%d %d\n%d %d",q1[x],q1[x],q1[x],q2[y]);
	return 0;
}