#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool b = false;
	for(int i = 1; i < s.size(); i ++)
	{
		if(s[i] < 'A' || s[i] > 'Z')
		{
			b = true;
		}
	}
	if(b == false)
	{
		for(int i = 0; i < s.size(); i ++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] - 'A' + 'a';
			}
			else
			{
				s[i] = s[i] - 'a' + 'A'; 
			}
		}
	}
	cout << s;
	return 0;
}