#include<cstdio>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
int n,m;
LL res,ans,mx=0;
int a[100002];
LL t[100002]={};
vector<int> vec[100002];
inline bool cmp(int a,int b)
{
	return a<b? 1:0;
}
inline int abs(int x)
{
	return x>0? x:-x;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==a[i-1])--i,--m;
	}
	for(int i=2,v;i<=m;++i)v=abs(a[i]-a[i-1]),ans+=v,t[a[i-1]]+=v,t[a[i]]+=v,vec[a[i]].push_back(a[i-1]),vec[a[i-1]].push_back(a[i]);
	for(int i=1,k;i<=n;++i)
		if(t[i])
		{
			sort(vec[i].begin(),vec[i].end(),cmp),k=vec[i][vec[i].size()/2],res=0;
			for(int j=0;j<vec[i].size();++j)res+=abs(vec[i][j]-k);mx=max(mx,t[i]-res);
		}
	printf("%lld",ans-mx);
	return 0;
}