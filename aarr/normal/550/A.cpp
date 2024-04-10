#include <iostream>

using namespace std;

int main()
{
	string s;
	int a = 0, b = 0, x = -1, y = 0;
	cin >> s;
	int i = 0;
	while(i < s.size() - 1)
	{
		if(s[i] == 'A' && s[i + 1] == 'B')
		{
			a ++;
			x = i;
		}
		if(s[i] == 'B' && s[i + 1] == 'A')
		{
			b ++;
			y = i;
		}
		i ++;
	}
	if(((a >= 1 && b >= 2) || (b >= 1 && a >= 2) || (a == 1 && b == 1 && x != y + 1 && y != x + 1)) && s != "ABAB" && s != "BABA" && s[0] != 'Q')
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}