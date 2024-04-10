#include <stdio.h>
#include <iostream>
#include <stdlib.h>


#define ull unsigned long long 

ull t[100050];
long n;
/*
void set(long l,ull d)
{
	for(;l<n;l=l|(l+1))
	{
		t[l] = max(t[l],d);
	}
}

ull getmax(long l)
{
	ull ans = 0;
	for(;l>=0;l=(l&(l+1))-1)
	{
		ans = max(ans,t[l]);
	}
}*/


int main()
{

	scanf("%ld",&n);
	for(long i=0;i<n;i++)
	{
		ull a;
		scanf("%I64d",&a);
		t[i] = a;
	}

	long m;
	scanf("%ld",&m);
	for(long i=0;i<m;i++)
	{
		ull w,h;
		scanf("%I64d %I64d",&w,&h);
		ull ans;
		if(t[0]>t[w-1])
			ans=t[0];
		else
			ans=t[w-1];

		
		t[0] = ans+h;

		printf("%I64d\n",ans);
	}

	return 0;
}