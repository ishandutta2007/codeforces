#include <iostream>

using namespace std;

bool palin(string s)
{
	for(int i = 0; i <= s.size() / 2; i ++)
	{
		if(s[i] != s[s.size() - i - 1])
		{
			return false;
		}	
	}
	return true;
}
int main()
{
	string s;
	cin >> s;
	bool a = false;
	for(int i = 0; i <= s.size(); i ++)
	{
		for(int j = 0; j < 26; j ++)
		{
			string t;
			for(int k = 0; k < s.size(); k ++)
			{
				if(k == i)
				{
					t += ('a' + j);
				}
				t += s[k];
			}
			if(i == s.size())
			{
				t += ('a' + j);
			}
			if(palin(t) == true && a == false)
			{
				cout << t;
				a = true;
			}
		}
	}
	if(a == false)
	{
		cout << "NA";
	}
	return 0;
}