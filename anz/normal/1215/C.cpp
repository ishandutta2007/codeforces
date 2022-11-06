#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
string s, t;

vector <int> a, b;
vector <pii> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> s >> t;

	int cnta = 0, cntb = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a') cnta++;
		else cntb++;
		if (t[i] == 'a') cnta++;
		else cntb++;

		if (s[i] != t[i])
		{
			if (s[i] == 'a') a.push_back(i + 1);
			else b.push_back(i + 1);
		}
	}

	if (cnta % 2 || cntb % 2)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < a.size() / 2; i ++)
		ans.push_back({ a[i*2],a[i*2 + 1] });
	for (int i = 0; i < b.size() / 2; i ++)
		ans.push_back({ b[i*2],b[i*2 + 1] });

	if (a.size() % 2)
	{
		ans.push_back({ a.back(), a.back() });
		ans.push_back({ a.back(), b.back() });
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << "\n";
}