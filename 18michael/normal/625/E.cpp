#include<cstdio>
#include<algorithm>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,v;
int id[100002],nx[100002],la[100002];
typedef pair<int,int> P;
set<P> S;
set<P>::iterator it;
struct aaa
{
	int p,a;
}w[100002];
inline bool cmp(int a,int b)
{
	return w[a].p<w[b].p? 1:0;
}
inline int dis(int x,int y)
{
	if(x==y)return inf;
	int d=(w[y].p-w[x].p+m)%m;
	if(x>y)d=(d+w[y].a)%m;
	if(d<=w[x].a)return 1;
	if(w[x].a<=w[y].a)return inf;
	return (d-w[y].a-1)/(w[x].a-w[y].a)+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&w[i].p,&w[i].a),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)la[nx[id[i]]=id[(i%n)+1]]=id[i];
	for(int i=1;i<=n;++i)S.insert(P(dis(i,nx[i]),i));
	while(!S.empty())
	{
		it=S.begin(),v=it->second;if(it->first==inf)break;
		S.erase(it),S.erase(P(dis(nx[v],nx[nx[v]]),nx[v])),S.erase(P(dis(la[v],v),la[v]));
		w[v].p+=dis(v,nx[v]),--w[v].a,la[nx[v]=nx[nx[v]]]=v;
		S.insert(P(dis(la[v],v),la[v])),S.insert(P(dis(v,nx[v]),v));
	}
	printf("%d\n",S.size());
	for(it=S.begin();it!=S.end();++it)printf("%d ",it->second);
	return 0;
}