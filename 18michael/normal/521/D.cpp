#include<cstdio>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
int k,n,m,p_t=0;
int op[100002];
LL a[100002];
typedef pair<int,int> P;
P b[100002];
vector<P> vec[100002];
struct aaa
{
	long double x;
	int id;
}p[100002];
inline bool cmp(P x,P y)
{
	return x.first>y.first? 1:0;
}
inline bool cmp1(aaa x,aaa y)
{
	return x.x>y.x? 1:0;
}
inline bool cmp2(aaa x,aaa y)
{
	return op[x.id]<op[y.id]? 1:0;
}
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;++i)scanf("%lld",&a[i]);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d%d%d",&op[i],&x,&y);
		if(op[i]==2)vec[x].push_back(P(y,i));
		else if(op[i]==3)p[++p_t]=(aaa){y,i};
		else if(y>b[x].first)b[x]=P(y,i);
	}
	for(int i=1;i<=k;++i)
	{
		if(b[i].first>a[i])vec[i].push_back(P(b[i].first-a[i],b[i].second));
		sort(vec[i].begin(),vec[i].end(),cmp);
		for(int j=0;j<vec[i].size();++j)p[++p_t]=(aaa){1.0*(a[i]+vec[i][j].first)/a[i],vec[i][j].second},a[i]+=vec[i][j].first;
	}
	printf("%d\n",m=min(m,p_t)),sort(p+1,p+p_t+1,cmp1),sort(p+1,p+m+1,cmp2);
	for(int i=1;i<=m;++i)printf("%d ",p[i].id);
	return 0;
}