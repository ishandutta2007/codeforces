#include<bits/stdc++.h>
#define Mx 500000
#define LL long long
#define mod 1000000007
using namespace std;
int n,m,k,t;
LL ans,tmp;
int X[500002],Y[500002],id[500002],rt[500002];
LL a[500002],Z[500002],pw[500002];
bool u[500002];
vector<int> vec;
inline bool cmp(int x,int y)
{
	return Z[x]<Z[y];
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void ins(int x)
{
	if(!u[x])u[x]=1,vec.push_back(x);
}
int main()
{
	for(int i=pw[0]=1;i<=Mx;++i)pw[i]=(pw[i-1]<<1)%mod;
	scanf("%d%d%d",&n,&m,&k),ans=((tmp=pw[n])*pw[k])%mod;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),rt[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d",&X[i],&Y[i]),Z[i]=(a[X[i]]^a[Y[i]]),id[i]=i;
	sort(id+1,id+m+1,cmp);
	for(int i=1,j;i<=m;i=j)
	{
		for(ans-=tmp,t=n,j=i;j<=m && Z[id[j]]==Z[id[i]];++j)
		{
			ins(X[id[j]]),ins(Y[id[j]]),getroot(X[id[j]]),getroot(Y[id[j]]);
			if(rt[X[id[j]]]^rt[Y[id[j]]])--t,rt[rt[X[id[j]]]]=rt[Y[id[j]]];
		}
		for(ans+=pw[t];vec.size();vec.pop_back())u[vec.back()]=0,rt[vec.back()]=vec.back();
	}
	return 0&printf("%lld",((ans%mod)+mod)%mod);
}