#include<cstdio>
#include<cstring>
#define lowbit(x) ((x)&(-(x)))
#define errlog(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
typedef double db;
int n;
inline int min(int x,int y)
{return(x<y)?x:y;}
inline int max(int x,int y)
{return(x>y)?x:y;}
inline int abs(int x)
{return(x>0)?x:-x;}
char str[1888888];
int dp[1888888];
void exec()
{
	scanf("%s",str+1),n=strlen(str+1);
	register int i;
	int tot=0;
	for(i=3;i<=n;i++)
	{
		if(str[i]=='e'&&str[i-1]=='n'&&str[i-2]=='o')
		{
			if(str[i+1]=='e')str[i-1]='!',tot++;
			else str[i]='!',tot++;
		}
		if(str[i]=='o'&&str[i-1]=='w'&&str[i-2]=='t')
		{
			if(str[i+1]=='o')str[i-1]='!',tot++;
			else str[i]='!',tot++;
		}
	}printf("%d\n",tot);
	for(i=1;i<=n;i++)
		if(str[i]=='!')printf("%d ",i);
	puts("");
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)exec();
	
}