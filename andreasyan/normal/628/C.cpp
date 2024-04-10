#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, m;
string s,ans;
int main()
{
	int i, j, k;
	cin >> n >> m;
	cin >> s;
	for (i = 0; i < n; ++i)
	{
		int han=-1;
		ans += '7';
		k = s[i] - 'a';
		for (j = 0; j < 26; ++j)
		{
			if (abs(k - j) > han && m - abs(k - j) >= 0)
			{
				han = abs(k - j);
				ans[i] = j + 'a';
			}
		}
		m -= han;
		if (ans[i] == '7')
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	if (m > 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}