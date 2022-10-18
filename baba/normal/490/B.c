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

int main()
{
	int back[MAX];
	int n;
	din(n);
	int i;
	int first,second;
	int front[MAX];
	int temp;
	memset(back,-1,sizeof back);
	memset(front,0,sizeof front);
	
	for(i=0;i<n;i++)
	{
		din(temp);
		front[temp]++;
		din(back[temp]);
		front[back[temp]]++;
		if(temp==0)
			second=back[temp];
	}
	for(i=0;i<MAX;i++)
		if(front[i]==1 && back[i]!=-1)
		{	first=i;
			break;
		}

	printf("%d %d ",first,second);
	while(!(back[first]==0 || back[second]==0))
	{
		first = back[first];
		second = back[second];
		printf("%d %d ",first,second);	
	}
	if(back[first]!=0)
		printf("%d ",back[first]);
	printf("\n");




	return 0;
}