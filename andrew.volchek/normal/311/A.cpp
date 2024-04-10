#include <iostream>

using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	if (p >= (n-1)*n/2)
		cout << "no solution";
	else
		for (int i = 0; i < n ; i++)
			cout << 0 << " " << i << endl;
	return 0;
}