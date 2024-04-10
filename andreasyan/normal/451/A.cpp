#include <iostream>
using namespace std;

int main()
{
	int n, m,mi;
	cin >> n >> m;
	if (n > m)
		mi = m;
	else
		mi = n;
	if (mi % 2 == 0)
		cout << "Malvika" << endl;
	else
		cout << "Akshat" << endl;
	return 0;
}