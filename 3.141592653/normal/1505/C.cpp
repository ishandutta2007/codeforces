#include<bits/stdc++.h>

char tmp[111111];

int main()
{
	scanf("%s",tmp);
	for(char*c=tmp+2;*c;c++)
	{
		//printf("%d ",*c-64);
		int a=c[0],b=c[-1],x=c[-2];
		if((a+64-(b+x-1))%26)
		{
			puts("NO");
			return 0;
		}
	}puts("YES");
}
/*
Happy April Fool's Day !!!11 
*/