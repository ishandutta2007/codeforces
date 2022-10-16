#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
typedef double db;
struct pii
{int x,y;
pii(int xx=0,int yy=0){x=xx,y=yy;}}p[1111111];
inline bool operator<(const pii x,cpnst pii y)
{return x.x<y.x;}
int a[1111111];
char str[1111111];
ll sum[1111111];
int n;
void exec()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		sum[a[i]-i+400000]+=a[i];
	ll ans=0;
	for(i=1;i<=800000;i++)
		if(sum[i]>ans)ans=sum[i];
	printf("%lld\n",ans);
}
int main()
{
	int T=1;
//	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/