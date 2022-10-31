#include <iostream>

using namespace std;


int main()
{
	long N,K;
	cin >> N >> K;

 	unsigned long long l,r;
	unsigned long long sum;
	unsigned long long d;
	l = 1;
	r = N;

	while(l!=r)
	{
		unsigned long long m = (l+r)/2;
		d = 1;
		sum = 0;

		while(m/d)
		{
			sum += m/d;
			d *= K;
		}
		if(sum >= N)
		{
			r = (l+r)/2;
		}
		else
		{
			l = (l+r)/2+1;
		}
	}
	cout << l;

	return 0;
}