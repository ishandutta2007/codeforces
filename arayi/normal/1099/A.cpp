#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
int m, h, m1, h1, m2, h2;
	
int main() 
{
	cin >> m >> h >> m1 >> h1 >> m2 >> h2;
	for (int i = h; i > 0; i--)
	{
		m += i;
		if (i == h1)
		{
			m = max(m - m1, 0);
		}
		else if (i == h2)
		{
			m = max(m - m2, 0);
		}
	}
	cout << m;
	return 0;
}