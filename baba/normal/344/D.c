#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}


int main()
{
	char stack[1000000];
	char pattern[100010];
	
	scanf("%s",pattern);

	stack[0]='.';
	int head=0;
	int i;
	for(i=0;pattern[i]!='\0';i++)
	{
		if(stack[head]==pattern[i])
			head--;
		else
			stack[++head]=pattern[i];
	}
	if(head==0)
		printf("YES\n");
	else
		printf("NO\n");





	return 0;
}