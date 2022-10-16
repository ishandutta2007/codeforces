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
int v[41111111],s[41111111];
#define sum(l,r) (s[r]-s[l]+v[l]) 
void exec()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(i=2;i<=3.4e7;i<<=1)
	{
		for(ii=0;ii<i;ii++)v[ii]=0;
		for(ii=1;ii<=n;ii++)
			v[a[ii]&(i-1)]++;
		s[0]=v[0];
		if(i==2)
		{
			int t=(v[0]*1ll*v[1])&1;
			ans|=t;
		}else
		{
			long long t=0;
			for(ii=1;ii<i;ii++)
			{
				if(ii&(i>>2))
				{
					t+=(v[ii]*1ll*(v[ii]-1))>>1;
				}s[ii]=s[ii-1]+v[ii];
			}
			for(ii=0;ii<i;ii++)
			{
				if(v[ii]%2==0)continue;
				int l=(i>>1)-ii,r=i-ii-1;
				//printf("%d[%d]-[%d,%d]\n",ii,v[ii],l,r);
				if(l<=0)
				{
					l+=i;
					if(l<=ii)l=ii+1;
					if(l<=(i-1))t+=sum(l,i-1);
				}
				else
				{
					if(l<=ii)l=ii+1;
					if(l<=r)t+=sum(l,r);
				}//printf("%d\n",t);
			}//printf("%d\n",t);
			if(t&1)ans|=(ii>>1);
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