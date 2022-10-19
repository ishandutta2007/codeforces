#include<bits/stdc++.h>
using namespace std;
int t,f[100];
const int N=100005;
char s[N],c[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s%s",s,c);
		int n=strlen(s);
		// f[0]=f[1]=f[2]=0;
		for (int i=0;i<26;++i)
			f[i]=0;
		for (int i=0;i<n;++i)
			++f[s[i]-'a'];
		if (c[0]=='a'&&c[1]=='b'&&f[0]&&f[1]&&f[2])
		{
			while (f[0]--)
				putchar('a');
			while (f[2]--)
				putchar('c');
			while (f[1]--)
				putchar('b');
			for (int i=3;i<26;++i)
			{
				while (f[i]--)
					putchar('a'+i);
			}
		}
		else
		{
			for (int i=0;i<26;++i)
			{
				while (f[i]--)
					putchar('a'+i);
			}
			// while (f[0]--)
			// 	putchar('a');
			// while (f[1]--)
			// 	putchar('b');
			// while (f[2]--)
			// 	putchar('c');

		}
		puts("");
	}
	return 0;
}