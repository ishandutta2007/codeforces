#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, a, b, c; 
	cin >> n >> a >> b >> c;
	if (n == 1) cout << 0;
	else
	{
		if (a <= b && a <= c)
			cout << a * (n - 1);
		else if (b <= a && b <= c)
			cout << b * (n - 1);
		else if (a <= b)
			cout << a + c * (n - 2);
		else cout << b + c * (n - 2);
	}
	return 0;
}