#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char s[1005];
char t[1000005];

int main()
{
	gets_s(s);
	gets_s(t);
	int l_s = strlen(s);
	int l_t = strlen(t);
	int it1 = 0;
	int pos_end = -1, pos_begin = -1;
	for (int i = 0; i < l_t; i++)
	{
		if (s[it1] == t[i])
		{
			it1++;
			if (it1 == l_s)
			{
				pos_end = i;
				break;
			}
		}
	}
	it1 = l_s - 1;
	for (int i = l_t - 1; i > -1; i--)
	{
		if (s[it1] == t[i])
		{
			it1--;
			if (it1 == -1)
			{
				pos_begin = i;
				break;
			}
		}
	}
	if (pos_begin == -1)
	{
		cout << 0 << endl;
	}
	else
		cout << max(0, pos_begin - pos_end) << endl;
	return 0;
}