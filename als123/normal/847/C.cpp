#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
int n;LL k,tmp;
//bool check[300010];
bool check(int x)
{
	//printf("%d %lld\n",x,tmp);
	if(x<=tmp) return tmp-=x,true;
	return false;
}
void dfs(int x)
{
	if(x==1){printf("()");return;}
	if(check(x-1))
	{
		printf("()");dfs(x-1);
		return;
	}
	else printf("(");dfs(x-1);printf(")");return;
}
int main()
{
	scanf("%d %lld",&n,&k);
	LL x=(LL)n-1;
	if(x*(x+1)/2<k)
	{
		printf("Impossible");
		return 0;
	}
	//memset(check,false,sizeof(check));
	tmp=x*(x+1)/2-k;
	/*for(int i=20;i>=0;i--)
		if((LL)(1<<i)<=tmp) tmp-=(1<<i),check[(1<<i)]=true;*/
	dfs(n);
}