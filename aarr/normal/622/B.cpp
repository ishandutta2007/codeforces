#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n;
	cin >> n;
	int h = (s[0] - '0') * 10 + (s[1] - '0'), m = (s[3] - '0') * 10 + (s[4] - '0');
	for(int i = 0; i < n; i ++)
	{
		m ++;
		if(m >= 60)
		{
			m = 0;
			h ++;
		}
		if(h >= 24)
		{
			h = 0;
		}
	}
	cout << h / 10 << h % 10 << ":" << m / 10 << m % 10;
	return 0;
}