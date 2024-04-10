#include<cstdio>
#include<cstring>
char s[78];
int ans[99];
int tp=0;
int main()
{
	scanf("%s",s);
	int L=strlen(s);
	while(true)
	{
		int target=0;
		for(int i=0;i<L;i++)
		{
			target*=10;
			if(s[i]!='0')
			{
				target++;
				s[i]--;
			}
		}
		if(target==0) break;
		ans[tp++]=target;
	}
	printf("%d\n",tp);
	for(int i=0;i<tp;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}