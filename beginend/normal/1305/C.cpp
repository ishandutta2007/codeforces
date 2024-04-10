#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;

int n,m,a[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n>m) {puts("0");return 0;}
	int ans=1;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]<a[j]) ans=(LL)ans*(a[j]-a[i])%m;
			else ans=(LL)ans*(a[i]-a[j])%m;
	printf("%d\n",ans);
	return 0;
}