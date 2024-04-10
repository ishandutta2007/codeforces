#include<bits/stdc++.h>
using namespace std;
int t,n,k;
long long x;
const int N=10005;
int a[N],f[N],cnt;
char s[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%lld",&n,&k,&x);
		--x;
		scanf("%s",s);
		for (int i=0;i<=cnt;++i)
			a[i]=0;
		cnt=0;
		for (int i=0;i<n;++i)
			if (s[i]=='a')
				++cnt;
			else
				++a[cnt];
		for (int i=0;i<=cnt;++i)
			a[i]=1+k*a[i];
		for (int i=cnt;i>=0;--i)
		{
			f[i]=x%a[i];
			x/=a[i];
		}
		for (int i=0;i<=cnt;++i)
		{
			for (int j=1;j<=f[i];++j)
				putchar('b');
			if (i!=cnt)
				putchar('a');
		}
		puts("");
	}
	return 0;
}