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
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n; string s;
	cin >> n >> s;
 
	int w = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B') b++;
		else w++;
	}
 
	vector <int> ans;
	if (b % 2 == 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == 'B')
			{
				ans.push_back(i + 1);
				s[i] = 'W';
				if (s[i + 1] == 'B') s[i + 1] = 'W';
				else s[i + 1] = 'B';
			}
		}
	}
	else if (w % 2 == 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == 'W')
			{
				ans.push_back(i + 1);
				s[i] = 'B';
				if (s[i + 1] == 'B') s[i + 1] = 'W';
				else s[i + 1] = 'B';
			}
		}
	}
	else
	{
		cout << -1;
		return 0;
	}
 
	cout << ans.size() << '\n';
	for (int it : ans) cout << it << ' ';
}