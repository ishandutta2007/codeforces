#include <stdio.h>

char arr[200];
int ori[200];
int cha[200];

int main()
{
	int n,c=0,i;
	scanf("%d%s",&n,arr);
	for(i=0;i<n;i++)
	{
		ori[i]=arr[i]-'0';
		cha[i]=ori[i];
	}
	cha[0]++;
	for(i=0;i<n;i++)
	{
		if(cha[i]==2)
		{
			cha[i]=0;
			cha[i+1]++;
		}
	}
	for(i=0;i<n;i++)
		if(ori[i]!=cha[i])
			c++;
	printf("%d",c);
	return 0;
}