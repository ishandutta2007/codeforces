#include<bits/stdc++.h>
#define bs 30
#define Mx 1000000
#define LL long long
using namespace std;
int Test_num,t=0,t1=0,p_t=-1,a_t,las,vec_t=0,edge_t=0;LL res;
int p[1000002],mnp[1000002]={},a[32],b[32],vec[302],num[30002]={},dis[30002],la[30002]={};
LL pw[32],to[30002],S[30002];
int d[302][2822],ans[302][302];
unordered_map<LL,int> mp,mp1;
queue<int> q;
struct aaa
{
	int to,nx;
}edge[218702];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int y,int z,LL w,int o,LL s)
{
	to[mp[w]=(++t)]=w,S[t]=s;
	if(!mp1.count(s))mp1[s]=(++t1);
	if(o && o<=Mx)vec[num[t]=(++vec_t)]=t;
	for(int i=1;i<=z;++i)
	{
		if(!y)break;
		if((o*=p[x])>Mx)o=0;
		dfs(x+1,--y,i,w+pw[x]*i,o,s*(i+1));
	}
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!mnp[i])p[++p_t]=mnp[i]=i;
		for(int j=0;j<=p_t && p[j]<=Mx/i;++j)
		{
			mnp[p[j]*i]=p[j];
			if(!(i%p[j]))break;
		}
	}
	pw[0]=1;
	for(int i=1;i<=bs;++i)pw[i]=pw[i-1]*(bs/i+1);
	dfs(0,bs,bs,0,1,1);
	for(int i=1;i<=t;++i)
	{
		res=0;
		for(int j=1;j<=bs;++j)res+=pw[j-1]*(b[j]=a[j]=(to[i]%pw[j])/pw[j-1]);
		for(int j=1;j<=bs;++j)
		{
			if(!b[j])break;
			if(j<bs && b[j]==b[j+1])continue;
			add_edge(i,mp[res-pw[j-1]]);
		}
	}
	for(int i=1;i<=vec_t;++i)
	{
		for(int j=1;j<=t;++j)dis[j]=-1;
		for(int j=1;j<=t1;++j)d[i][j]=Mx;
		dis[vec[i]]=0,q.push(vec[i]);
		for(int p;!q.empty();)
		{
			p=q.front(),q.pop();
			d[i][mp1[S[p]]]=min(d[i][mp1[S[p]]],dis[p]);
			for(int i=la[p],v;i;i=edge[i].nx)if(!(~dis[v=edge[i].to]))dis[v]=dis[p]+1,q.push(v);
		}
	}
	for(int i=1;i<=vec_t;++i)
		for(int j=1;j<=vec_t;++j)
		{
			ans[i][j]=Mx;
			for(int k=1;k<=t1;++k)ans[i][j]=min(ans[i][j],d[i][k]+d[j][k]);
		}
}
inline int get(int x)
{
	for(res=a_t=0;x>1;)
	{
		for(t=0,las=mnp[x];!(x%las);x/=las,++t);
		a[++a_t]=t;
	}
	sort(a+1,a+a_t+1);
	for(int i=a_t;i;--i)res+=a[i]*pw[a_t-i];
	return num[mp[res]];
}
int main()
{
	init(),read(Test_num);
	for(int x,y;Test_num--;)read(x),read(y),printf("%d\n",ans[get(x)][get(y)]);
	return 0;
}