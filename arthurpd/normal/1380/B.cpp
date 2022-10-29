#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		map<char, int> cnt;
		for (char c : s)
		{
			cnt[c]++;
		}

		char ans = 'R';
		if (cnt['R'] >= cnt['S'] && cnt['R'] >= cnt['P'])
			ans = 'P';
		else if (cnt['P'] >= cnt['S'] && cnt['P'] >= cnt['R'])
			ans = 'S';

		cout << string(s.size(), ans) << endl;
	}
}