#include <iostream>

using namespace std;

int main()
{
	string s, t, b = "YES";
	cin >> s;
	cin >> t;
	if(s.size() != t.size())
	{
		b = "NO";
	}
	else
	{
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i] != t[s.size() - i - 1])
			{
				b = "NO";
			}
		}
	}
	cout << b;
	return 0;
}