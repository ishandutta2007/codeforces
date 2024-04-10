#include<bits/stdc++.h>
#define Mx 7000
using namespace std;
int n,q,p_t=0;
int p[7002],mnp[7002],mu[7002];
bitset<7002> bs[100002],a[7002],b[7002];
inline void init()
{
	mu[1]=1;
	for(int i=2;i<=Mx;++i)
	{
		if(!mnp[i])p[++p_t]=mnp[i]=i,mu[i]=-1;
		for(int j=1;j<=p_t && p[j]*i<=Mx;++j)
		{
			mnp[p[j]*i]=p[j];
			if(!(i%p[j]))break;
			mu[p[j]*i]=-mu[i];
		}
	}
	for(int i=1;i<=Mx;++i)
		for(int j=i;j<=Mx;j+=i)
		{
			a[j].set(i);
			if(mu[j/i])b[i].set(j);
		}
}
int main()
{
	init(),scanf("%d%d",&n,&q);
	for(int o,x,y,z;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)bs[x]=a[y];
		else if(o==2)scanf("%d",&z),bs[x]=(bs[y]^bs[z]);
		else if(o==3)scanf("%d",&z),bs[x]=(bs[y]&bs[z]);
		else printf("%d",(bs[x]&b[y]).count()&1);
	}
	return 0;
}