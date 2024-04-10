#include <iostream>

using namespace std;

bool pr(int n)
{
	for(int i = 2; i * i <= n; i ++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int a[1005];
int main()
{
	int n, k, m = 0, s = 0;
	cin >> n;
	cin >> k;
	for(int i = 3; i < n; i ++)
	{
		if(pr(i) == true)
		{
			a[m] = i;
			m ++;
		}
	}
	for(int i = 0; i < m - 1; i ++)
	{
		if(a[i] + a[i + 1] + 1 <= n && pr(a[i] + a[i + 1] + 1) == true)
		{
			s += 1;
		}
	}
	if(k <= s)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}