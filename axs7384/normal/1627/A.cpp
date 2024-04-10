#include<bits/stdc++.h>
using namespace std;
int t,n,m,r,c;
const int N=5005;
char s[N][N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&n,&m,&r,&c);
		for (int i=1;i<=n;++i)
		{
			scanf("%s",s[i]+1);
			// cout<<"?"<<i<<' '<<s[i]<<endl;
		}
		int b=0;
		if (s[r][c]=='B')
		{
			puts("0");
			continue;
		}
		for (int i=1;i<=n;++i)
			if (s[i][c]=='B')
				b=1;
		for (int i=1;i<=m;++i)
			if (s[r][i]=='B')
				b=1;
		if (b)
		{
			puts("1");
			continue;
		}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				if (s[i][j]=='B')
					b=1;
		if (b)
			puts("2");
		else
			puts("-1");
	}
	return 0;
}