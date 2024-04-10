#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000 + 1;

int cnt[N][26];

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int l = (int) s.size();
	double ans = 0;
	int grab = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		for (int i = 1; i < l; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				cnt[i][j] = 0;
			}
		}
		for (int j = 0; j < l; j++)
		{
			if (s[j] == c)
			{
				for (int i = 1; i < l; i++)
				{
					cnt[i][s[(i + j) % l] - 'a']++;
				}
			}
		}
		int mx = 0;
		for (int i = 1; i < l; i++)
		{
			int ct = 0;
			for (int cur = 0; cur < 26; cur++)
			{
				if (cnt[i][cur] == 1)
				{
					ct++;
				}
			}
			mx = max(mx, ct);
		}
		grab += mx;
	}
	cout << fixed << setprecision(20) << grab / (double) l << '\n';
}