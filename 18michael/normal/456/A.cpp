#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct aaa
{
	int a,b;
}x[100002];
inline bool cmp(aaa a,aaa b)
{
	return a.a<b.a? 1:0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i].a,&x[i].b);
	sort(x+1,x+n+1,cmp);
	for(int i=2;i<=n;++i)
		if(x[i].b<x[i-1].b)
			return 0&puts("Happy Alex");
	return 0&puts("Poor Alex");
}