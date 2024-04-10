#include<bits/stdc++.h>
using namespace std;
char s[1000],t[1000];
int n,m;
inline bool pd(int l,int r)
{
	int p=0;
	for (int i=l;i<=r;++i)
	{
		++p;
		if (s[i]!=t[p])
		{
			// cout<<i<<' '<<p<<endl;
			return false;
		}
	}
	int q=r;
	while (p<m)
	{
		++p;
		--q;
		if (q==0)
			return false;
		if (s[q]!=t[p])
		{
			// cout<<p<<' '<<q<<endl;
			return false;
		}
	}
	return true;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		bool b=false;
		for (int i=1;i<=n;++i)
			for (int j=i;j<=n;++j)
				if (j-i+1<=m&&pd(i,j))
					b=true;
		puts(b?"YES":"NO");
	}
	return 0;
}