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

#define MAX 1000010

char key[MAX];
int lrem[MAX],rrem[MAX];
int a,b;

int main()
{
	scanf("%s",key);
	scanf("%d %d",&a,&b);
	int len = strlen(key);
	int i;
	int t1=0,t2=0;
	int P = 1;
	for(i=0;i<len;i++)
	{
		t1=(t1*10+key[i]-'0') % a;
		lrem[i]=t1;

		t2=((key[len-i-1]-'0')*P + t2) % b;
		P = (P*10)%b;
		rrem[len-i-1]=t2;
	}
	int leftlen=len;
	for(i=0;i<len;i++)
		if(lrem[i]==0 && rrem[i+1]==0)
		{
			while(!(key[i+1]-'0'))
				i++;
			leftlen=i;
			break;
		}
	
	if(leftlen >= len-1)
		printf("NO\n");
	else
	{
		printf("YES\n");
		for(i=0;i<=leftlen;i++)
			putchar(key[i]);
		putchar('\n');
		for(;i<len;i++)
			putchar(key[i]);
		putchar('\n');
		
	}




	return 0;
}