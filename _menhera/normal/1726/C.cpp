#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--)
	{
		int N;
		string s;
		cin >> N >> s;
		int lv = 0;
		int a = N;
		for (int i = 0; i < 2 * N - 1; i++)
			if (s[i] == ')' && s[i + 1] == '(')
				--a;
		cout << a << '\n';
	}
}