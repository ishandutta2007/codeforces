#include <iostream>
#include <cstring>

using namespace std;

bool check(int n)
{
	bool used[10];
	memset(used,0,10);
	while(n)
	{
		if(used[n%10])
			return false;
		used[n%10] = 1;
		n /= 10;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for(int i=n+1;i<10000;i++)
	{
		if(check(i))
		{
			cout << i;
			break;
		}
	}

	return 0;
}