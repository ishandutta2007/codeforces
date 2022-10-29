#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int first = n;
		for (int i = 0; i < n; i++)
			if (s[i] == '8')
			{
				first = i;
				break;
			}
		
		if (n - first >= 11)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}