#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const int size1 = 4e5;
const int INF = 1e9;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, i;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	static bool book[1005][1005];
	static bool  met[size1];
	for (int i = 0; i < n; i++)
	{
		met[s[i]] = true;
	}
	static bool res[size1];
	for (int i = 1; i <= k; i++)
	{
		string s1;
		cin >> s1;
		res[i] = true;
		for (int j = 0; j < s1.size(); j++)
		{
			if (s[j] != '*' && s1[j] != s[j])
			{
				res[i] = false;
			}
			if (s[j] == '*' && met[s1[j]])
			{
				//book[i][s1[j]] = false;
				res[i] = false;
			}
			if (s[j] == '*')
			{
				book[i][s1[j]] = true;
			}
		}
	}
	static bool per[1005];
	for (int i = 0; i <= 500; i++)
	{
		per[i] = true;
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (!book[j][i] && res[j])
			{
				per[i] = false;
			}
		}
	}
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (per[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}