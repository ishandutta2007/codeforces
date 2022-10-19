#include<cstdio>
#define Mx 512
#define LL long long
#define mod 998244353
int n,m,edge_t=0,head=1,tail=0,p,vec_t;
int la[100002]={},sg[100002],deg[100002]={},q[100002],cnt[100002]={},vec[100002];
LL Matrix[515][515]={};
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void Topo()
{
	for(int i=1;i<=n;++i)if(!deg[i])q[++tail]=i;
	while(head<=tail)
	{
		p=q[head],++head,vec_t=0;
		for(int i=la[p],v;i;i=edge[i].nx)
		{
			if(!deg[v=edge[i].to])
			{
				if(!cnt[sg[v]])vec[++vec_t]=sg[v];
				++cnt[sg[v]];
			}
			else
			{
				--deg[v];
				if(!deg[v])q[++tail]=v;
			}
		}
		for(int i=0;;++i)
			if(!cnt[i])
			{
				sg[p]=i;
				break;
			}
		for(int i=1;i<=vec_t;++i)cnt[vec[i]]=0;
	}
}
inline LL Gauss()
{
	LL v;
	for(int i=0;i<Mx;++i)
		for(int j=i+1;j<Mx;++j)
		{
			v=(Matrix[j][i]*pow(Matrix[i][i],mod-2))%mod;
			for(int k=i;k<=Mx;++k)Matrix[j][k]=(Matrix[j][k]-v*Matrix[i][k])%mod;
		}
	for(int i=Mx-1;~i;--i)
		for(int j=0;j<i;++j)
			v=(Matrix[j][i]*pow(Matrix[i][i],mod-2))%mod,Matrix[j][i]=0,Matrix[j][Mx]=(Matrix[j][Mx]-v*Matrix[i][Mx])%mod;
	return (Matrix[0][Mx]*pow(Matrix[0][0],mod-2))%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	Topo();for(int i=1;i<=n;++i)++cnt[sg[i]];
	for(int i=0;i<Mx;++i)
	{
		for(int j=0;j<Mx;++j)Matrix[i][j]=cnt[(i^j)];
		Matrix[i][i]-=(n+1),Matrix[i][Mx]-=(i>0);
	}
	printf("%lld",(Gauss()+mod)%mod);
	return 0;
}