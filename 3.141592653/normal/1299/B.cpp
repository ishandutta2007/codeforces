#include<cstdio> 
#include<algorithm>
struct pii 
{
	int x,y;
}p[1111111];
int n;
inline bool operator<(const pii x,const pii y)
{if(x.x^y.x)return x.x<y.x;return x.y<y.y;}
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("YES"),0;
	else if(n&1)return puts("NO"),0;
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	std::sort(p+1,p+n+1);
	int mx=(p[1].x+p[n].x),my=(p[1].y+p[n].y);
	for(i=2;i*2<=n;i++)
	{
		int tx=(p[i].x+p[n-i+1].x),ty=p[i].y+p[n-i+1].y;
		if(tx!=mx)return puts("NO"),0;
		if(my!=ty)return puts("NO"),0;
	}puts("YES");
}