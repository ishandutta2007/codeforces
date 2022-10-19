#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=125005,M=26;
char s1[N],s2[N];
int n,m,a[N],b[N],ans,mp[M],vis,MP[M][M];
inline void write(int x)
{
	if (!x)
		putchar('0');
	int a[15];
	a[0]=0;
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar(a[a[0]--]+'0');
	putchar(' ');
}
int main()
{
	// freopen("9.in","r",stdin);
	scanf("%s",s1+1); 
	n=strlen(s1+1);
	scanf("%s",s2+1); 
	m=strlen(s2+1);
	// freopen("9.out","w",stdout);
	// n=125000;
	// for (int i=1;i<=n;++i)
	// 	s1[i]=rand()%26+'a';
	// m=n/2;
	// for (int i=1;i<=m;++i)
	// 	s2[i]=rand()%26+'a';
	for (int i=1;i<=n;++i)
		a[i]=s1[i]-'a';
	for (int i=1;i<=m;++i)
		b[i]=s2[i]-'a';
	for(int kkk=0;kkk<n-m+1;++kkk)
	{
		memset(MP,0,sizeof(MP));
		for (int i=0;i<M;++i)
			MP[i][i]=1;
		for (int j=1;j<=m;++j)
			MP[b[j]][a[kkk+j]]=1;
		memset(mp,0,sizeof(mp));
		for (int i=0;i<M;++i)
			for (int j=0;j<M;++j)
				MP[i][j]|=MP[j][i];
		for (int i=0;i<M;++i)
			for (int j=0;j<M;++j)
				mp[i]|=MP[i][j]<<j;
		vis=0;
		ans=26;
		for (int i=0;i<M;++i)
			for (int j=0;j<M;++j)
				if (mp[j]&(1<<i))
					mp[j]|=mp[i];
		for (int i=0;i<M;++i)
			if (!(vis&(1<<i)))
			{
				--ans;
				vis|=mp[i];
			}
		write(ans); 
	}
	return 0;
}