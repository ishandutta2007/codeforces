#include<cstdio>
#include<map>
#include<vector>
#define LL long long
using namespace std;
int n,t=0,edge_t=1;
LL a,b,c,d,A,B,C,D,E;
typedef pair<LL,LL> P;
typedef pair<int,int> P1;
map<P,int> mp;
int la[400002]={};
bool vis[400002]={};
vector<P1> vec;
vector<int> son[400002];
struct aaa
{
	int to,nx;
	bool u;
}edge[400002];
inline LL gcd(LL x,LL y)
{
	return y? gcd(y,x%y):x;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t;
}
inline void dfs(int x)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(!vis[v=edge[i].to])
		{
			edge[i].u=edge[i^1].u=1,dfs(v);
			if(son[v].size())vec.push_back(P1(son[v][0],(i>>1)));
			else son[x].push_back(i>>1);
		}
		else if(!edge[i].u)edge[i].u=edge[i^1].u=1,son[x].push_back(i>>1);
	while(son[x].size()>1)vec.push_back(P1(son[x][son[x].size()-1],son[x][son[x].size()-2])),son[x].pop_back(),son[x].pop_back();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d),A=a*d+b*d,B=b*c,E=gcd(A,B),A/=E,B/=E,C=a*d,D=b*c+b*d,E=gcd(C,D),C/=E,D/=E;
		if(!mp.count(P(A,B)))mp[P(A,B)]=(++t);
		if(!mp.count(P(C,D)))mp[P(C,D)]=(++t);
		add_edge(mp[P(A,B)],mp[P(C,D)]);
	}
	for(int i=1;i<=t;++i)if(!vis[i])dfs(i);
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d %d\n",vec[i].first,vec[i].second);
	return 0;
}