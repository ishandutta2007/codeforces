#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string a, b;
	int n;
	cin >> n >> b;
	for (int i = 0; i < b.length(); i++)
	{
		a += b[i];
		i += a.length();
	}
	cout << a;
	return 0;
}