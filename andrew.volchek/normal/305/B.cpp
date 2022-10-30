#include <iostream>

using namespace std;

#define ull unsigned long long

ull gcd(ull a, ull b)
{
	return a ? gcd(b % a, a) : b;
}



int main()
{
	ull p, q, a[99], b[99];
	int n;
	cin >> p >> q >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
		bool good = true;
	for (int i = 0; i < n; i++)
	{
		if (q == 0)
		{
			good = false;
			break;
		}
		
		ull c = p / q;
		if (c >= a[i])
		{
			if (c != a[i])
				c--;
			p -= q*c;
			swap(p, q);
		}
		else
		{
			good = false;
			break;
		}
	}
	
	if (q != 0)
		good = false;
	
			
	if (good)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}