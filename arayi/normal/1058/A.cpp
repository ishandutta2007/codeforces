#include <iostream>
using namespace std;


int main()
{
	int n;
	int a, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a)
			b = a;
	}
	if (b)
		cout << "HARD";
	else
		cout << "EASY";
    return 0;
}