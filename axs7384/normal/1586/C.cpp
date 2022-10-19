#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m;
char s[N],c[N];
int f[N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=2;i<=n;++i)
	{
		scanf("%s",c+1);
		for (int j=2;j<=m;++j)
			if (s[j]=='X'&&c[j-1]=='X')
				f[j]=1;
		for (int j=1;j<=m;++j)
			s[j]=c[j];
	}
	for (int i=1;i<=m;++i)
		f[i]+=f[i-1];
	int q,l,r;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d",&l,&r);
		puts(f[r]-f[l]==0?"YES":"NO");
	}
}