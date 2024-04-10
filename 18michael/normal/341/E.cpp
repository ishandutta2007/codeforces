#include<bits/stdc++.h>
using namespace std;
int n,t,st_t=0;
int a[1002],st[1002];
typedef pair<int,int> P;
vector<P> vec;
inline void ins(int x,int y)
{
	a[y]-=a[x],a[x]<<=1,vec.push_back(P(x,y));
}
inline void solve(int &x,int &y,int &z)
{
	for(;;)
	{
		if(a[x]>a[y])swap(x,y);
		if(a[x]>a[z])swap(x,z);
		if(a[y]>a[z])swap(y,z);
		if(!a[x])return ;
		for(t=a[y]/a[x];t;t>>=1)if(t&1)ins(x,y);else ins(x,z);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i])st[++st_t]=i;
	}
	if(st_t<2)return 0&puts("-1");
	for(;st_t>2;--st_t)solve(st[st_t],st[st_t-1],st[st_t-2]);
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d %d\n",vec[i].first,vec[i].second);
	return 0;
}