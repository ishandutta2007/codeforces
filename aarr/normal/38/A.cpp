#include <iostream>

using namespace std;

int l[105];
int main()
{
	int n, a, b, c = 0;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> l[i];
	}
	cin >> a;
	cin >> b;
	for(int i = a - 1; i < b - 1 ; i++)
	{
		c += l[i];
	}
	cout << c;
	return 0;
}