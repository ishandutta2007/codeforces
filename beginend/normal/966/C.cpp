#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n,tot[65];
LL bin[65],a[65][N],ans[N];

int main()
{
	bin[0]=1;
	for (int i=1;i<=60;i++) bin[i]=bin[i-1]*2;
	scanf("%d",&n);
	LL s=0;
	for (int i=1;i<=n;i++)
	{
		LL x;scanf("%I64d",&x);
		s^=x;
		for (int j=60;j>=0;j--)
			if (x&bin[j]) {a[j][++tot[j]]=x;break;}
	}
	int now=0;
	for (int i=1;i<=n;i++)
	{
		bool flag=0;
		for (int j=0;j<=60;j++)
			if (tot[j]&&(s&bin[j]))
			{
				flag=1;
				ans[++now]=a[j][tot[j]];
				tot[j]--;
				s^=ans[now];
				break;
			}
		if (!flag) {puts("No");return 0;}
	}
	puts("Yes");
	for (int i=n;i>=1;i--) printf("%I64d ",ans[i]);
	return 0;
}