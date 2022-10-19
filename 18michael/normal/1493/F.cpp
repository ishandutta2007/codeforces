#include<bits/stdc++.h>
#define Mx 1000
using namespace std;
int n,m,t,ans,p_t=0;
int p[1002];
bool u[1002];
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
inline int calc(int x)
{
	int t,res=1;
	for(int i=1;i<=p_t;++i)
		if(!(x%p[i]))
		{
			for(t=0;!(x%p[i]);++t,x/=p[i]);
			res*=(t+1);
		}
	return res;
}
int main()
{
	init(),scanf("%d%d",&n,&m),t=n;
	for(int i=1,x;i<=p_t;++i)
		for(;!(t%p[i]);)
		{
			if(i==1)
			{
				printf("? %d %d %d %d %d %d\n",t/2,m,1,1,1+t/2,1),fflush(stdout),scanf("%d",&x);
				if(!x)break;
				t/=2;
			}
			else
			{
				printf("? %d %d %d %d %d %d\n",t/p[i]*(p[i]/2),m,1,1,1+t/p[i]*(p[i]/2),1),fflush(stdout),scanf("%d",&x);
				if(!x)break;
				printf("? %d %d %d %d %d %d\n",t/p[i]*(p[i]/2),m,1,1,1+t/p[i]*(1+p[i]/2),1),fflush(stdout),scanf("%d",&x);
				if(!x)break;
				t/=p[i];
			}
		}
	ans=calc(n/t),t=m;
	for(int i=1,x;i<=p_t;++i)
		for(;!(t%p[i]);)
		{
			if(i==1)
			{
				printf("? %d %d %d %d %d %d\n",n,t/2,1,1,1,1+t/2),fflush(stdout),scanf("%d",&x);
				if(!x)break;
				t/=2;
			}
			else
			{
				printf("? %d %d %d %d %d %d\n",n,t/p[i]*(p[i]/2),1,1,1,1+t/p[i]*(p[i]/2)),fflush(stdout),scanf("%d",&x);
				if(!x)break;
				printf("? %d %d %d %d %d %d\n",n,t/p[i]*(p[i]/2),1,1,1,1+t/p[i]*(1+p[i]/2)),fflush(stdout),scanf("%d",&x);
				if(!x)break;
				t/=p[i];
			}
		}
	return 0&printf("! %d",ans*calc(m/t));
}