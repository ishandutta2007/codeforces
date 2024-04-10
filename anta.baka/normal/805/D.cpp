#include <bits/stdc++.h>

using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;

int n, ans, pw[1000001];
string s;
int t;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	n = s.size();
	pw[0] = 1;
	for(int i = 0; i < n; i++)
	{
		pw[i + 1] = (pw[i] + pw[i]) % mod;
		if(s[i] == 'b')
		{
			ans = (ans + pw[t] - 1) % mod;
		}
		else t++;
	}
	cout << ans;
}