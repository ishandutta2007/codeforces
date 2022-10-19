#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char s[4];
		cin >> s;
		ans += (s[0] == '+' || s[1] == '+') * 2 - 1;
	}
	cout << ans << endl;
}