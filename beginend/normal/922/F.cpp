#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=300005;

int n,k,f[N];
bool vis[N];

int main()
{
	scanf("%d%d",&n,&k);
	LL s=0;
	for (int i=1;i<=n;i++) s+=n/i-1;
	if (s<k) {puts("No");return 0;}
	puts("Yes");
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			f[j]++;
	for (int i=n;i>=2;i--)
	{
		if (i>n/2&&f[i]==2) continue;
		int w=f[i]-1;
		for (int j=i*2;j<=n;j+=i) w+=(!vis[j]);
		if (s-w>=k) s-=w,vis[i]=1;
	}
	for (int i=n/2+1;i<=n;i++)
	{
		if (s==k) break;
		if (f[i]==2) vis[i]=1,s--;
	}
	int tot=0;
	for (int i=1;i<=n;i++) tot+=(!vis[i]);
	printf("%d\n",tot);
	for (int i=1;i<=n;i++) if (!vis[i]) printf("%d ",i);
	return 0;
}