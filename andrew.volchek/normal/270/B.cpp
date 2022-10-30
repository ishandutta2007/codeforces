#include <iostream>
#include <stdio.h>

using namespace std;

long n;
long t[100005];
long a[100005];

void init()
{
	for(long i=0;i<=n;i++)
	{
		t[i] = 0;
	}
}

long sum(long l)
{
	long ans = 0;
	for(;l>=0;l=((l+1)&l)-1)
		ans += t[l];
	return ans;
}

void add(long p)
{
	for(;p<n+1;p=((p+1)|p))
		t[p]++; 
}



int main()
{
	cin >> n;
	//n=100000;
	//init();

	for(long i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
		//a[i] = n-i;
	}

	long ans = 0;

	for(long i=n-1;i>=0;i--)
	{
		if(sum(a[i]))
		{
			ans+=i+1;
			break;
		}
		add(a[i]);
	}

	cout << ans;

	return 0;
}