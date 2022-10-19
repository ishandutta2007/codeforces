#include<cstdio>
#include<algorithm>
using namespace std;
int n,t=0,now=0;
struct aaa
{
	int pos,opt;
}p[400002];
inline bool cmp(aaa a,aaa b)
{
	return (a.pos==b.pos)? (a.opt>b.opt):(a.pos<b.pos);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)scanf("%d%d",&x,&y),p[++t]=(aaa){x,1},p[++t]=(aaa){y,-1};
	sort(p+1,p+t+1,cmp);
	for(int i=1;i<=t;++i)
	{
		now+=p[i].opt;
		if(now>2)return 0&puts("NO");
	}
	return 0&puts("YES");
}