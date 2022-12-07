#include<cstdio>
int n;
char s[5];
char ss[105][5];
int main()
{
	scanf("%s",s);
	scanf("%d",&n);
	bool tf=false;
	for (int u=1;u<=n;u++)
	{
		scanf("%s",ss[u]);
		if (ss[u][0]==s[0]&&ss[u][1]==s[1])
			tf=true;
	}
	for (int u=1;u<=n;u++)//
	{
		if (ss[u][1]==s[0])
		{
			for (int i=1;i<=n;i++)
			{
				if (ss[i][0]==s[1])
					tf=true;
			}
		}
	}
	if (tf) printf("YES\n");
	else printf("NO\n");
	return 0;
}