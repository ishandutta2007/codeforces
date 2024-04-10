#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],f[N];
int t,n;
inline void sc(int n)
{
	for (int i=1;i<=2*n;++i)
		f[i]=0;
	for (int i=1;i<=n;++i)
		f[a[i]]=1;
	for (int i=1;i<=2*n;++i)
		putchar(f[i]?'(':')');
	puts("");
}
inline void nxt(int n)
{
	for (int i=n;i>=2;--i)
		if (a[i]<=(i-1)*2)
		{
			++a[i];
			for (int j=i+1;j<=n;++j)
				a[j]=a[j-1]+1;
			return;
		}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			a[i]=i;
		sc(n);
		for (int i=1;i<n;++i)
		{
			nxt(n);
			sc(n);
		}
	}
	return 0;
}