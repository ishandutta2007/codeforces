#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105,M=8205;
int n,m,q,e[13],u[N],v[N],t[N],no[M];ll f[M][13];
inline int p(int s,int i){return s>>i&1;} 
int main()
{
	scanf("%d%d%d",&n,&m,&q);int S=(1<<n)-1;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),u--,v--,e[u]|=(1<<v),e[v]|=(1<<u);
	for(int i=1;i<=q;i++)scanf("%d%d%d",&u[i],&v[i],&t[i]),u[i]--,v[i]--,t[i]--;
	for(int s=1;s<=S;s++)for(int j=1;j<=q;j++)if(p(s,u[j])&&p(s,v[j])&&!p(s,t[j])||p(s,t[j])&&(!p(s,u[j])||!p(s,v[j])))no[s]=1;
	for(int s=1;s<=S;s++)for(int i=0;i<n;i++)if(p(s,i))
	{
		int ss=s^(1<<i),mx=-1;
		for(int j=0;j<n;j++)if(p(ss,j))mx=j;
		if(!ss){f[s][i]=1;continue;}
		for(int t=ss;t;t=(t-1)&ss)if(!no[t]&&p(t,mx))for(int j=0;j<n;j++)if(p(t,j)){if((e[j]&(t|(1<<i)))==e[j])f[s][i]+=f[s^t][i]*f[t][j];}
	}
	printf("%lld\n",f[S][0]);
	return 0;
}