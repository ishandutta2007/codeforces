#include<bits/stdc++.h>
#define Mx 200000
using namespace std;
int n,f,p_t=0,ans=0;
int p[200002],sg[200002];
bool u[200002];
bitset<200002> tmp;
bitset<200002> bs[102];
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
	for(int i=1;i<=p_t;++i)for(int j=i;j<=p_t && p[j]<=Mx/p[i];++j)u[p[i]*p[j]]=0;
	u[f]=1;
	for(int i=2;i<=Mx;++i)if(!u[i])tmp.set(i);
}
int main()
{
	scanf("%d%d",&n,&f),init();
	for(int i=0;i<=Mx;++i)
	{
		for(sg[i]=0;bs[sg[i]].test(i);++sg[i]);
		bs[sg[i]]|=(tmp<<i);
	}
	for(int i=1,x,y,z;i<=n;++i)scanf("%d%d%d",&x,&y,&z),ans^=sg[y-x-1]^sg[z-y-1];
	return 0&puts(ans? "Alice\nBob":"Bob\nAlice");
}