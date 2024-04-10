#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1005;
char a[N],b[N];
int n,m,q;
int cnt[N];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",a+1,b+1);
	for (int u=1;u<=n-m+1;u++)
	{
		bool tf=true;
		cnt[u]=cnt[u-1];
		for (int i=1;i<=m;i++)
			if (a[u+i-1]!=b[i])
				tf=false;
		cnt[u]=cnt[u]+tf;
	}
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r=r-m+1;
		if (l>r) printf("0\n");
		else printf("%d\n",cnt[r]-cnt[l-1]);
	}
	return 0;
}