#include<cstdio>
#include<cstring>
int n;
int a[1111111];
char str[1111111];
int main()
{
	int T; 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str+1);
		for(register int i=1;str[i];i++)
		{
			if(str[i]=='?')
			{
				str[i]=str[i-1]+1;
				for(register char c='a';c<'d';c++)
					if(c^str[i-1])
						if(c^str[i+1])
							str[i]=c;
			}
		}
		for(register int i=1;str[i];i++)
			if(str[i]==str[i+1])goto FL;
		puts(str+1);
		continue;
		FL:puts("-1");
	}
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/