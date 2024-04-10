#include<cstdio>
#include<algorithm>
#define Mx 29
using namespace std;
int n,tree_t;
struct aaa
{
	int num;
	int to[2];
}tree[6000002]={};
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void insert(int x)
{
	int now=0;
	for(int i=Mx,j;~i;--i)
	{
		j=((x>>i)&1);
		if(!tree[now].to[j])tree[now].to[j]=(++tree_t);
		now=tree[now].to[j],++tree[now].num;
	}
}
inline int dp(int now,int x)
{
	if(tree[now].to[0])
	{
		if(tree[now].to[1])return max(dp(tree[now].to[0],x-1),dp(tree[now].to[1],x-1))+1;
		return dp(tree[now].to[0],x-1);
	}
	if(tree[now].to[1])return dp(tree[now].to[1],x-1);
	return tree[now].num;
}
int main()
{
	scanf("%d",&n),tree[0].num=n;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),insert(x);
	printf("%d",n-dp(0,Mx));
	return 0;
}