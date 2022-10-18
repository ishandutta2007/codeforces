#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define min(a,b) a<b?a:b
#define max(a,b) a<b?b:a

#define gu getchar_unlocked 
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)

#define MAX 2000001

int isPrime[MAX];

int main()
{
	int i,j,t,x,y,k,l,count;
	//Sieve
	isPrime[0]=isPrime[1]=0;
	for(i=2;i<MAX;i++)
		isPrime[i]=1;
	
	for(i=2;i*i<MAX;i++)
		if(isPrime[i])
			for(j=i*i;j<MAX;j+=i)
				isPrime[j]=0;
	
//	scanf("%d",&t);
//	while(t--)
//	{
		scanf("%d %d %d",&x,&y,&k);
		
		count=0;
		for(i=y;i>=0 && count<k;i--)
			if(isPrime[i])
				count++;
		i++;

		if(i<x)
			printf("-1\n");
		else
		{
			l=y-i+1;
			j=y;//j=back pointer,i=front pointer
			count = k;
			while(i>x)
			{

				i--;
			//	printf("%d %d %d\n",i,j,l);
				if(isPrime[j] && !isPrime[i])
				{
					if(count==k)
						l++;
					else
					{
						count--;
						j--;
					}
				}
				else if(!isPrime[j] && isPrime[i])
				{
					count++;
					j--;
				}
				else
					j--;
			}
			printf("%d\n",l);
		}
//	}
	
	return 0;
}