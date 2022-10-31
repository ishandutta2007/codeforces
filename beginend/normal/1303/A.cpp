#include<bits/stdc++.h>

char str[105];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%s",str+1);
		int n=strlen(str+1);
		int lef=n+1,rig=0,s=0;
		for (int i=1;i<=n;i++)
			if (str[i]=='1')
			{
				s++;
				rig=i;
				lef=std::min(lef,i);
			}
		if (!s) puts("0");
		else printf("%d\n",rig-lef+1-s);
	}
	return 0;
}