#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=105;

int n,nx[N][26],ls[26],a[N];
LL m,f[N][N],cnt[N];
char s[N];

int main()
{
	scanf("%d%lld",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'a';
	for (int i=n;i>=0;i--)
	{
		for (int j=0;j<26;j++) nx[i][j]=ls[j];
		ls[a[i]]=i;
	}
	f[0][0]=1;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
		{
			if (!f[i][j]) continue;
			f[i][j]=std::min(f[i][j],m);
			for (int k=0;k<26;k++)
				if (nx[i][k]) f[nx[i][k]][j+1]+=f[i][j];
		}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
			cnt[j]+=f[i][j];
	LL ans=0;
	for (int i=n;i>=0;i--)
	{
		LL w=std::min(m,cnt[i]);
		ans+=(LL)w*(n-i);
		m-=w;
	}
	if (m) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}