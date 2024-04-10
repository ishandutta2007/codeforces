#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
#define inlien inline
#define retrun return
#define cpnst const
inline ll min(ll x,ll y)
{return(x>y)?y:x;}
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
int n,m;
ll a[1111111];
char str[1111111];
void exec()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str+1);
	int tot=0;
	register int i;
	for(i=1;i<=n;i++)if(str[i]=='(')tot++;
	if(tot*2!=n) 
	{return (void)puts("-1");}
	int ans=0;
	int tt=0,var=0;
	for(i=1;i<=n;i++)
	{
		if(tt<=0)var++;
		if(str[i]=='(')
		{
			tt++;
			if(tt==0)ans+=var,var=0;
		}else
		{
			tt--;
			if(tt==0)var=0;
		}
	}printf("%d\n",ans);
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