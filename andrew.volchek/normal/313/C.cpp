#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;


long long a[1111111];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", a+i);
		a[i] = -a[i];
	}
	sort(a, a+n); 
	int nn = 0; 
	while (n != 1)
	{
		nn++;
		n /= 4;
	}
	long long ans = 0;
	int curr = 0;
	int currp = 1;
	for (int i = 0; i <= nn; i++)
	{
		int t = curr;
		
		for (int j = 0; j < (currp) - (t?t:0); j++)
		{
			ans += ((long long)(nn-i+1))*a[curr];
			curr++;
		}
		currp *= 4;
		
	}
	cout << -ans;
}