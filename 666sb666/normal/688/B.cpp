#include<cstdio>
#include<cstring>
const int maxn=100001; 
char s[maxn];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)putchar(s[i]);
	for(int i=len-1;i>=0;i--)putchar(s[i]);
	putchar('\n');
	return 0;
}