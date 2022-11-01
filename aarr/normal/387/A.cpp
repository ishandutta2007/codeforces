#include <iostream>

using namespace std;

int main()
{
	string s, t;
	cin >> s;
	cin >> t;
	int sh = (s[0] - '0') * 10 + (s[1] - '0'), sm = (s[3] - '0') * 10 + (s[4] - '0'), th = (t[0] - '0') * 10 + (t[1] - '0'), tm = (t[3] - '0') * 10 + (t[4] - '0');
	int a = sh * 60 + sm, b = th * 60 + tm, c = a - b;
	if(c < 0)
	{
		c = 60 * 24 + c;
	}
	int ph = (c / 60), pm = (c % 60);
	if(ph < 10)
	{
		cout << 0;
	}
	cout << ph << ":";
	if(pm < 10)
	{
		cout << 0;
	}
	cout << pm;
	return 0;
}