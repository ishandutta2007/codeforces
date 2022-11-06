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

string s;
deque <int> d[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		d[s[i] - 'a'].push_back(i);
	}

	vector <int> ans1, ans2;

	int lptr = 0, rptr = s.size() - 1;

	while (ans1.size() + ans2.size() < s.size() / 2)
	{


		int maxNum = -1;
		int res = -1;

		int dist[3] = { -1,-1,-1 };
		for (int i = 0; i < 3; i++)
		{
			while (!d[i].empty() && d[i].front() < lptr) d[i].pop_front();
			while (!d[i].empty() && d[i].back() > rptr) d[i].pop_back();

			if (d[i].empty()) continue;
			dist[i] = d[i].back() - d[i].front();
			if (dist[i] > maxNum) maxNum = dist[i], res = i;
		}

		if (res == -1) break;

		if (d[res].size() == 1)
		{
			ans1.push_back(res);
			break;
		}

		ans1.push_back(res);
		ans2.push_back(res);

		lptr = d[res].front() + 1, rptr = d[res].back() - 1;
		d[res].pop_front();
		d[res].pop_back();
	}

	if (ans1.size() + ans2.size() >= s.size() / 2)
	{
		for (int i = 0; i < ans1.size(); i++) cout << (char)(ans1[i]+'a');
		for (int i = 0; i < ans2.size(); i++) cout << (char)(ans2[ans2.size() - 1 - i] + 'a');
	}
	else cout << "IMPOSSIBLE";
}