#include <stdio.h>
#include <string.h>

char arr[1001];
char res[1001];
int acn[26];
int bcn[26];

int main()
{
	int r=0,al,bl,i;
	scanf("%s%s",arr,res);
	al=strlen(arr);
	bl=strlen(res);
	for(i=0;i<al;i++)
		acn[arr[i]-'a']++;
	for(i=0;i<bl;i++)
		bcn[res[i]-'a']++;
	for(i=0;i<26;i++)
	{
		if(bcn[i]!=0&&acn[i]==0)
		{
			printf("-1");
			return 0;
		}
		r+=acn[i]<bcn[i]?acn[i]:bcn[i];
	}
	printf("%d",r);
	return 0;
}