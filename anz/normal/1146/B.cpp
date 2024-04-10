#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s;
	cin >> s;

	string tmp = s;
	for (int i = 0; i < tmp.length();)
	{
		if (tmp[i] == 'a') tmp.replace(i, 1, "");
		else i++;
	}

	bool flag = true;
	string s1, s2;

	if (tmp.length() % 2)
		flag = false;
	else
	{
		for (int i = 0; i < tmp.length()/2; i++)
		{
			if (s[s.length() - 1 - i] == 'a')
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			s1 = tmp.substr(0, tmp.size() / 2);
			s2 = tmp.substr(tmp.size() / 2, tmp.size() / 2);
			if (s1 != s2) flag = false;
		}
	}

	if (flag)
		cout << s.substr(0,s.length()-tmp.length()/2);
	else
		cout << ":(";
}