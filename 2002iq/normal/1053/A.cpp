#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int g=__gcd(n,k);
	n/=g;
	k/=g;
	int g2=__gcd(m,k);
	m/=g2;
	k/=g2;
	if (k==1)
	{
		if (g>1)
		n*=2;
		else if (g2>1)
		m*=2;
		else
		{
			cout << "NO";
			return 0;
		}
	}
	if (k>2)
	cout << "NO";
	else
	printf("YES\n0 0\n0 %d\n%d 0",m,n);
}