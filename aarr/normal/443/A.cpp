#include <iostream>

using namespace std;

char a[400];
int main()
{
	int m = 0;
	string s;
	getline(cin, s);
	for(int i = 1; i < s.size(); i += 3)
	{
		bool b = true;
		for(int j = 0; j < m; j ++)
		{
			if(s[i] == a[j])
			{
				b = false;
			}
		}
		if(s[i] > 'z' || s[i] < 'a')
		{
			b = false;
		}
		if(b == true)
		{
			a[m] = s[i];
			m ++;
		}
	}
	cout << m;
	return 0;
}