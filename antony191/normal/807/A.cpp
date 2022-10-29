#include <iostream>

using namespace std;

int main()
{
	int n, i;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	bool o = false, s = false;
	for (i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		if (a[i] != b[i]) o = true;
		if (i > 0 && a[i] > a[i - 1]) s = true;
	}
	if (o == true) cout << "rated";
	else if (s == true) cout << "unrated";
	else cout << "maybe";
	return 0;
}