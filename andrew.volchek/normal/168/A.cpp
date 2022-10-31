#include <iostream>

using namespace std;


int main()
{
	long n,x,y;
	cin >> n >> x >> y;
	long a = n * y;
	long b = x * 100;
	long c = a-b;
	if(c<0)
		cout << 0;
	else
	{
		long d = c/100;
		if(c%100)
			d++;
		cout << d;
	}
	return 0;
}