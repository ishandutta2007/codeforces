#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=60005;

int n,ans[N];

void solve(LL s)
{
	int tot=0;LL w=0;
	for (int i=n;i>=1;i--)
		if (s>=i) s-=i,ans[++tot]=i,w+=i;
	printf("%I64d\n%d ",abs((LL)n*(n+1)/2-w*2),tot);
	for (int i=tot;i>=1;i--) printf("%d ",ans[i]);
}

int main()
{
	scanf("%d",&n);
	LL s=(LL)n*(n+1)/2;
	solve((s+1)/2);
	return 0;
}