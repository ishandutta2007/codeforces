#include <iostream>
using namespace std;

int main()
{
	int n, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		bool h;
		cin >> h;
		x += h;
		cin >> h;
		x += h;
		cin >> h;
		x += h;
		ans += x >= 2;
	}
	cout << ans << endl;
}