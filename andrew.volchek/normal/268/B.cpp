#include <iostream>

using namespace std;


int main()
{
	unsigned long long n;
	cin >> n;

	unsigned long long ans = 0;

	for(unsigned long long i=0;i<n;i++)
	{
		ans += (n-i);
		if(i!=(n-1) && i)
			ans += (n-i-1)*i;
	}

	cout << ans;

	return 0;
}