#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0, t = 0;
	cin >> n;
	for(int i = 2; i < n; i ++)
	{
		int a = n;
		while(a >= i)
		{
			sum += a % i;
			a = a / i;
		}
		t += 1;
		sum += a;
	}
	for(int i = 2; i * i <= sum; i ++)
	{
		for(int j = 2; j * j <= sum; j ++)
		{
			if(sum % j == 0 && t % j == 0)
			{
				sum = sum / j;
				t = t / j;
			} 
		}
	}
	cout << sum << "/" << t;
	return 0;
}