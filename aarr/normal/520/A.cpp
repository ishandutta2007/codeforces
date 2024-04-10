#include <iostream>

using namespace std;

int main()
{
	int n;
	string s, t;
	cin >> n;
	cin >> s;
	if(n < 26)
	{
		cout << "NO";
	}
	else
	{
		for(int i = 0; i < n; i ++)
		{
			char c = s[i];
			if(c >= 'A' && c <= 'Z')
			{
				c = c - 'A' + 'a';
			}
			bool b = true;
			for(int j = 0; j < t.size(); j ++)
			{
				if(t[j] == c)
				{
					b = false;
				}
			}
			if(b)
			{
				t += c;
			}
		}
		if(t.size() == 26)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	return 0;
}