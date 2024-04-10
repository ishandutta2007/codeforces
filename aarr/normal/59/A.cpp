#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			a += 2;
		}
		a --;
	}
	if(a >= 0)
	{
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] - 'A' + 'a';
			}
		}
	}
	else
	{
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] = s[i] - 'a' + 'A';
			}
		}
	}
	cout << s;
	return 0;
}