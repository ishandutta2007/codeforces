#include <stdio.h> 

int main()
{
	long long n,i,num,tmp;
	char s[2000001];
	bool which;
	scanf("%lld",&n);
	while(n--)
	{
		which=0,scanf("%s",s);
		if(s[0] == 'R')
		{
			for(i=1;s[i]>='A';i++) ;
			for(;s[i]!='\0';i++)
			{
				if(s[i] == 'C')
				{
					which=1,s[i++] = '\0';
					break;
				}
			}
		}
		if(which)
		{
			tmp = i;
			for(num=0;s[i]!='\0';i++) num = num*10+s[i]-'0';
			for(s[2000000]='\0',i=2000000;num;) s[--i] = (num-1)%26+'A',num = num/26 - (num%26==0);
			printf("%s%s\n",s+i,s+1);
		}
		else
		{
			for(num=0,i=0;s[i]>='A';i++) num = num*26+s[i]-'A'+1;
			printf("R%sC%lld\n",s+i,num);
		}
	}
}