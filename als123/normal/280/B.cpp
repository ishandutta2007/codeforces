#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int n;
int sta[N],top;
int ans;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		while (top>0&&a[sta[top]]<a[u])
		{
			ans=max(ans,a[u]^a[sta[top]]);
			top--;
		}
		if (top>0) ans=max(ans,a[u]^a[sta[top]]);
		sta[++top]=u;
	}
	printf("%d\n",ans);
	return 0;
}