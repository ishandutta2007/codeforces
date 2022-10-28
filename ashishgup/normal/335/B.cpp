#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2600;

int n;
string s;
int cache[N][N];

int dp(int i, int j)
{
	if(j < i)
		return 0;
	if(i == j)
		return 1;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	if(s[i] != s[j])
		ans = max(dp(i + 1, j), dp(i, j - 1));
	else
		ans = 2 + dp(i + 1, j - 1);
	return ans;
}

string a = "", b = "";

void path(int i, int j)
{
	if(j < i)
		return;
	if(a.size() + b.size() == 100)
		return;
	if(i == j)
	{
		a += s[i];
		return;
	}
	if(s[i] == s[j])
	{
		a += s[i];
		b += s[j];
		return path(i + 1, j - 1);
	}
	else
	{
		if(dp(i + 1, j) > dp(i, j - 1))
			return path(i + 1, j);
		else
			return path(i, j - 1);
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> s;
	n = s.size();
	map<char, int> m;
	for(auto &it:s)
		m[it]++;
	for(auto &it:m)
	{
		if(it.second >= 100)
		{
			for(int j = 1; j <= 100; j++)
				cout << it.first;
			exit(0);
		}
	}
	//String length is now less than 2600
	int ans = dp(0, n - 1);
	path(0, n - 1);
	reverse(b.begin(), b.end());
	a += b;
	cout << a;
	return 0;
}