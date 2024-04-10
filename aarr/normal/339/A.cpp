#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.size() / 2; i ++)
	{
		for(int j = 0; j < s.size() - 2; j += 2)
		{
			if(s[j] > s[j + 2])
			{
				swap(s[j], s[j + 2]);
			}
		}
	}
	cout << s;
	return 0;
}