#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

const int MAXN=500005;

int n,k,m;
int a[MAXN],b[MAXN],cur[MAXN];
int pre[MAXN],res[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int s,x;
	scanf("%d%d%d%d",&m,&k,&n,&s);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=s;i++)
	{
		scanf("%d",&x);
		++b[x];
	}
	int l=1,r,cnt=500000;
	for(int i=1;i<=500000;i++)
		if(!b[i])--cnt;
	for(int i=1;i<=m;i++)
	{
		++cur[a[i]];
		if(cur[a[i]]==b[a[i]])--cnt;
		for(;l<=i-k+1 && !cnt;++l)
		{
			if(cur[a[l]]==b[a[l]])++cnt;
			--cur[a[l]];
		}
		pre[i]=l-1;
	}
	l=r=0;
	for(int i=1;i<=m;i++)
		if(pre[i] && (pre[i]-1)/k+(m-i)/k+1>=n)
			{l=pre[i];r=i;break;}
	if(!r)return 0*printf("-1\n");
	memset(cur,0,sizeof(cur));
	int t=0;
	for(int i=l;i<=r;i++)
	{
		if(cur[a[i]]<b[a[i]])++cur[a[i]];
		else if(r-l+1-t>k)res[++t]=i;
	}
	for(int i=1;i<=(l-1)%k;i++)res[++t]=i;
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d ",res[i]);
	return 0;
}