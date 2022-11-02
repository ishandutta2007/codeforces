#include <iostream>

using namespace std;

int main()
{
	int a = 0, c = 0;
	string s;
	while(getline(cin, s))
	{
		if(s[0] == '+')
		{
			a ++;
		}
		if(s[0] == '-')
		{
			a --;
		}
		if(s[0] != '+' && s[0] != '-')
		{
			int b;
			for(int i = 0; i < s.size(); i ++)
			{
				if(s[i] == ':')
				{
					b = i;
				}
			}
			c = c + (s.size() - b - 1) * a;
 		}
	}
	cout << c;
}