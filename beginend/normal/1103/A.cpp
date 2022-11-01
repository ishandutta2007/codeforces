#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

char str[1005];
bool c[5],r[5];

int main()
{
	scanf("%s",str);
	int len=strlen(str);
	for (int i=0;i<len;i++)
		if (str[i]=='0')
		{
			if (!r[1]) r[1]=1,printf("%d %d\n",1,1);
			else r[1]=0,printf("%d %d\n",3,1);
		}
		else
		{
			if (!c[1]) c[1]=1,printf("%d %d\n",1,2);
			else if (!c[2]) c[2]=1,printf("%d %d\n",2,2);
			else if (!c[3]) c[3]=1,printf("%d %d\n",3,2);
			else c[1]=c[2]=c[3]=0,printf("%d %d\n",4,2);
		}
	return 0;
}