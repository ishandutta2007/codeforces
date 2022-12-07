#include<cstdio>
const int N=5005;
int A[N];
int n;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&A[u]);
	bool tf=false;
	for (int u=1;u<=n;u++)
	{
		int a=u,b=A[a],c=A[b];
		if (a!=b&&b!=c&&A[c]==a) tf=true;
	}
	if (tf) printf("YES\n");
	else printf("NO\n");
	return 0;
}