#include <iostream>

using namespace std;

int main()
{
	int n, a = 1, b = 0;
	string t, p;
	cin >> n;
	cin >> t;
	for(int i = 1; i < n; i ++)
	{
		string s;
		cin >> s;
		if(s == t)
		{
			a ++;
		}
		else
		{
			p = s;
			b ++;
		}
	}
	if(a > b)
	{
		cout << t;
	}
	else
	{
		cout << p;
	}
	return 0;
}