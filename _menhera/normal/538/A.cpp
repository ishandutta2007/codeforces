#include<cstdio>
#include<cstring>

int main()
{
	char s[110];
	scanf("%s",s);
	char tg[]="CODEFORCES";
	int L=strlen(s);
	for(int i=-1;i<L;i++)
	{
		for(int j=i+1;j<=L;j++)
		{
			//0,1, ..., i , j, ... ,L-1
			if(i+1+L-j!=10)
				continue;
			bool flag=false;
			for(int k=0;k<=i;k++)
				if(tg[k]!=s[k]) flag=true;
			for(int k=j;k<=L-1;k++)
				if(tg[k-j+i+1]!=s[k]) flag=true;
			if(flag) continue;
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}