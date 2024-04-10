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
	int n;
	din(n);
	int i;
	int a[5000],b[5000],c[5000];
	int alen=0,blen=0,clen=0;
	int minl=0;
	int temp;
	for(i=0;i<n;i++)
	{
		din(temp);
		switch(temp)
		{
			case 1 : a[alen++]=i+1;
				 break;
			case 2 : b[blen++]=i+1;
				 break;
			case 3 : c[clen++]=i+1;
				 break;
		}
	}
	minl = min(alen,min(blen,clen));
	dout(minl);
	for(i=0;i<minl;i++)
		printf("%d %d %d\n",a[i],b[i],c[i]);


	return 0;
}