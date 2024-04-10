#include<bits/stdc++.h>
#define Mx 100000
#define LL long long
using namespace std;
int n,st_t=0,p_t=0,res;LL ans=1;
int a[100002],cnt[100002],st[100002],mu[100002],p[100002],mnp[100002];
bool u[100002];
vector<int> vec[100002];
inline void init()
{
	mu[1]=1;
	for(int i=2;i<=Mx;++i)
	{
		if(!mnp[i])p[++p_t]=i,mu[i]=-1;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			mnp[p[j]*i]=p[j];
			if(!(i%p[j]))break;
			mu[p[j]*i]=-mu[i];
		}
	}
}
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
}
int main()
{
	init(),scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),u[a[i]]=1;
	for(int i=Mx;i;--i)for(int j=i;j<=Mx;j+=i)u[i]|=u[j],vec[j].push_back(i);
	for(int i=Mx;i;--i)
		if(u[i])
		{
			res=0;
			for(int j=0;j<vec[i].size();++j)res+=mu[vec[i][j]]*cnt[vec[i][j]];
			while(st_t)
			{
				for(int j=0;j<vec[st[st_t]].size();++j)if(!(i%vec[st[st_t]][j]))res-=mu[vec[st[st_t]][j]];
				if(!res)break;
				for(int j=0;j<vec[st[st_t]].size();++j)--cnt[vec[st[st_t]][j]];
				--st_t;
			}
			ans=max(ans,(LL)i*st[st_t]/gcd(i,st[st_t])),st[++st_t]=i;
			for(int j=0;j<vec[i].size();++j)++cnt[vec[i][j]];
		}
	return 0&printf("%lld",ans);
}