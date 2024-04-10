#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	int n;
	cin >> n;
	cin >> a;
	int i = 0, b = 0, c = 0;
	for (i = 0; i < n - 1; ++i)
	{
		if (a[i] == 'S' && a[i + 1] == 'F') ++b;
		else if (a[i] == 'F' && a[i + 1] == 'S') ++c;
	}
	if (b > c) cout << "YES";
	else cout << "NO";
	return 0;
}