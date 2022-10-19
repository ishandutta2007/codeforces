#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,mnd,edge_t,Test_num;
int dep[102],rt[102],la[102],fa[102];
int dis[102][102];
char s[102][102][102];
vector<int> vec[102];
struct aaa
{
	int to,nx;
}edge[202];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	//printf("ADD %d %d\n",x,y);
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline int query(int a,int b,int c)//d(a,c)=d(b,c)
{
	assert(a!=b);
	if(a>b)swap(a,b);
	return s[a][b-a][c]^48;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f,int d,int rt)
{
	dis[rt][x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1,rt);
}
inline void solve()
{
	read(n),mnd=inf,edge_t=0;
	for(int i=1;i<=n+1;++i)vec[i].clear(),la[i]=fa[i]=0;
	for(int i=1;i<n;++i)for(int j=1;j<=n-i;++j)scanf("%s",s[i][j]+1);
	for(int i=1;i<=n;++i)
	{
		dep[i]=0;
		for(int j=1;j<=n;++j)rt[j]=j;
		for(int j=1;j<=n;++j)for(int k=j+1;k<=n;++k)if(query(j,k,i))getroot(j),getroot(k),rt[rt[j]]=rt[k];
		for(int j=1;j<=n;++j)dep[i]+=((getroot(j),rt[j])==j);
		//printf("dep[%d]:%d\n",i,dep[i]);
		mnd=min(mnd,dep[i]),vec[dep[i]].push_back(i);
	}
	if(vec[mnd].size()==2)add_edge(vec[mnd][0],vec[mnd][1]),fa[vec[mnd][0]]=vec[mnd][1],fa[vec[mnd][1]]=vec[mnd][0];
	else
	{
		++mnd;
		for(int i=0;i<vec[mnd].size();++i)add_edge(vec[mnd][i],vec[mnd-1][0]),fa[vec[mnd][i]]=vec[mnd-1][0];
	}
	for(int i=mnd+1;i<=n;++i)
		for(int j=0;j<vec[i].size();++j)
		{
			bool ok=0;
			for(int k=0;k<vec[i-1].size();++k)
				if(query(vec[i][j],fa[vec[i-1][k]],vec[i-1][k]))
				{
					add_edge(vec[i][j],vec[i-1][k]),fa[vec[i][j]]=vec[i-1][k],ok=1;
					break;
				}
			if(!ok)return (void)(puts("No"));
		}
	//puts("ok");
	for(int i=1;i<=n;++i)dfs(i,0,1,i);
	/*for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			printf("%2d%c",dis[i][j],j==n? '\n':' ');*/
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=1;k<=n;++k)
				if((dis[i][k]==dis[j][k])!=query(i,j,k))
					return (void)(puts("No"));
	puts("Yes");
	for(int i=1;i<=n;++i)for(int j=la[i];j;j=edge[j].nx)if(edge[j].to>i)printf("%d %d\n",i,edge[j].to);
}
int main()
{
	read(Test_num);
	while(Test_num--)solve();
	return 0;
}