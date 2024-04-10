#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n,a[30],b[N],m;
char s[N];

void ins(int x,int y)
{
	for (int i=m+1;i>x;i--) b[i]=b[i-1];
	m++;
	b[x+1]=y;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) a[s[i]-'a']++;
		int tot=0;
		for (int i=0;i<26;i++) if (a[i]) b[++tot]=i;
		if (tot>3)
		{
			for (int i=tot/2+1;i<=tot-(tot&1);i++)
			{
				for (int j=1;j<=a[b[i]];j++) putchar(b[i]+'a');
				for (int j=1;j<=a[b[i-tot/2]];j++) putchar(b[i-tot/2]+'a');
			}
			if (tot&1) for (int j=1;j<=a[b[tot]];j++) putchar(b[tot]+'a');
			puts("");
		}
		else if (tot==1)
		{
			for (int i=1;i<=n;i++) putchar(b[1]+'a');
			puts("");
		}
		else if (tot==2)
		{
			if (b[1]+1==b[2]) puts("No answer");
			else
			{
				for (int i=1;i<=n;i++) putchar(s[i]);
				puts("");
			}
		}
		else
		{
			if (b[1]+1==b[2]&&b[2]+1==b[3]) puts("No answer");
			else
			{
				if (b[1]+1==b[2]) std::swap(b[2],b[3]);
				else if (b[2]+1==b[3]) std::swap(b[1],b[2]);
				for (int i=1;i<=a[b[1]];i++) putchar(b[1]+'a');
				for (int i=1;i<=a[b[2]];i++) putchar(b[2]+'a');
				for (int i=1;i<=a[b[3]];i++) putchar(b[3]+'a');
				puts("");
			}
		}
	}
	return 0;
}