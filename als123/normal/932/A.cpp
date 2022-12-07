#include<cstdio>
#include<cstring>
const int N=1005;
char ss[N];
int main()
{
	scanf("%s",ss+1);
	int len=strlen(ss+1);
	for (int u=1;u<=len;u++) printf("%c",ss[u]);
	for (int u=len;u>=1;u--) printf("%c",ss[u]);
	return 0;
}