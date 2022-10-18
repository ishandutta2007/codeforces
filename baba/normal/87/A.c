#include<stdio.h>

#define ull unsigned long long 


void swap(ull int* a,ull int* b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

/*ull int find_lcm(ull int big,ull int small)
{
	ull int i=0;
	if(big<small)
		swap(&big,&small);
	for(i=big;!(i%big==0 && i%small==0);i++);
	return i;
}*/

ull int gcd(ull int big,ull int small)
{
	if(small==0) return big;
	else return gcd(small,big%small);
}

ull int find_lcm(ull int big,ull int small)
{
	ull int ans;
	ans = big*small / gcd(big,small);
	return ans;
}

int main()
{
	ull int a,b,M=0,D=0,lcm,left=0,right=0,i=1,j=1;
	scanf("%llu %llu",&a,&b);
	
	lcm=find_lcm(a,b);

	while(right<lcm)
	{
		left=right;
		if(a*i<b*j)
		{
			right=a*i;
			i++;
			D++;
		}
		else if(a*i>b*j)
		{
			right=b*j;
			j++;
			M++;
		}
		else if(a<b)
		{
			right=b*j;
			j++;
			M++;
		}
		else
		{
			right=a*i;
			i++;
			D++;
		}
			
	}
	if(M<D)
		printf("Dasha\n");
	else if(D<M)
		printf("Masha\n");
	else
		printf("Equal\n");
	return 0;

		
}