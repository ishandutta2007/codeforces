#include<bits/stdc++.h>
using namespace std;
int t;
const int N=26;
int f[N][N][N];
char s[100005][6];
int n;
int l[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		bool b=false;
		for (int i=1;i<=n;++i)
		{
			scanf("%s",s[i]+1);
			l[i]=strlen(s[i]+1);
			if (s[i][1]==s[i][l[i]])
				b=true;
		}
		if (b)
		{
			puts("YES");
			continue;
		}
		for (int i=0;i<26;++i)
			for (int j=0;j<26;++j)
				for (int k=0;k<26;++k)
					f[i][j][k]=0;
		for (int i=1;i<=n;++i)
		{
			if (l[i]==2)
			{
				for (int k=0;k<26;++k)
				{
					if (f[s[i][2]-'a'][s[i][1]-'a'][k])
						b=true;
					f[s[i][1]-'a'][s[i][2]-'a'][k]=1;
				}
			}
			else
			{
				if (f[s[i][3]-'a'][s[i][2]-'a'][s[i][1]-'a'])
					b=true;
				f[s[i][1]-'a'][s[i][2]-'a'][s[i][3]-'a']=1;
			}
		}
		if (b)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}