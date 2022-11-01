#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	string s, t;
	cin >> s;
	while(i < s.size())
	{
		if(s[i] == 'W' && i < s.size() - 2 && s[i + 1] == 'U' && s[i + 2] == 'B')
		{
			i += 3;
			if(t.size() && t[t.size()] - 1 != ' ')
			{
				t += ' ';
			}
		}
		else
		{
			t += s[i];
			i ++;
		}
	}
	cout << t;
	return 0;
}