#include <bits/stdc++.h>

using namespace std;

int gh, n, a;
char pat[10]={'a', 'b', 'a', 'c', 'a', 'b', 'a'};
char s[100];
char odp[100];

bool chck1(int x)
{
	for(int i=0; i<7; ++i)
	{
		if(s[x+i]!=pat[i])
		{
			return false;
		}
	}
	return true;
}

bool chck2(int x)
{
	for(int i=0; i<7; ++i)
	{
		if(s[x+i]!=pat[i] && s[x+i]!='?')
		{
			return false;
		}
	}
	return true;
}

bool chck3(int x)
{
	for(int i=0; i<7; ++i)
	{
		if(odp[x+i]!=pat[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		scanf("%s", s+1);
		s[0]='a';
		s[n+1]='a';
		for(int i=0; i<=n+1; ++i)
		{
			odp[i]=s[i];
		}
		a=0;
		for(int i=1; i<=n-6; ++i)
		{
			a+=chck1(i);
		}
		if(a>1)
		{
			printf("NO\n");
			continue;
		}
		if(a==1)
		{
			for(int i=1; i<=n; ++i)
			{
				if(s[i]=='?')
				{
					s[i]='d';
				}
			}
			printf("YES\n");
			for(int i=1; i<=n; ++i)
			{
				printf("%c", s[i]);
			}
			printf("\n");
		}
		else
		{
			a=0;
			for(int i=1; i<=n-6; ++i)
			{
				if(chck2(i))
				{
					for(int j=0; j<7; ++j)
					{
						odp[i+j]=pat[j];
					}
					a=0;
					for(int j=1; j<=n-6; ++j)
					{
						a+=chck3(j);
					}
					if(a>1)
					{
						for(int j=0; j<7; ++j)
						{
							odp[i+j]=s[i+j];
						}
					}
					else
					{
						for(int j=1; j<=n; ++j)
						{
							if(odp[j]=='?')
							{
								odp[j]='d';
							}
						}
						printf("YES\n");
						for(int j=1; j<=n; ++j)
						{
							printf("%c", odp[j]);
						}
						printf("\n");
						a=-5;
						break;
					}
				}
			}
			if(a!=-5)
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}