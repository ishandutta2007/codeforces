#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;

string l[100001];

set <pair<pii, int> > mp;

set <pair<pii, int> > tmp;

vector <pii> ans_1;
vector <pii> ans_2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		l[i] = str;

		int v = 0;
		int lv = -1;
		for (int i = 0; i < str.size(); i++)
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			{
				v++, lv = str[i];
			}

		mp.insert({ {v,lv} ,i });
	}

	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		auto j = i; j++;
		if (j == mp.end())
		{
			tmp.insert(*i);
			break;
		}
		auto s1 = *i, s2 = *j;

		if (s1.first.first != s2.first.first || s1.first.second != s2.first.second)
		{
			tmp.insert(s1);
			continue;
		}

		ans_2.push_back({ s1.second, s2.second });
		i++;
	}

	for (auto i = tmp.begin(); i != tmp.end(); i++)
	{
		auto j = i; j++;
		if (j == tmp.end()) break;
		auto s1 = *i, s2 = *j;

		if (s1.first.first != s2.first.first)
		{
			continue;
		}

		ans_1.push_back({ s1.second,s2.second });
		i++;
	}

	if (ans_1.size() >= ans_2.size())
	{
		cout << ans_2.size() << "\n";
		for (int i = 0; i < ans_2.size(); i++)
		{
			cout << l[ans_1[i].first] << ' ' << l[ans_2[i].first] << "\n";
			cout << l[ans_1[i].second] << ' ' << l[ans_2[i].second] << "\n";
		}
	}
	else
	{
		cout << ans_1.size() + (ans_2.size() - ans_1.size()) / 2 << "\n";
		int i = 0;
		for (i = 0; i < ans_1.size(); i++)
		{
			cout << l[ans_1[i].first] << ' ' << l[ans_2[i].first] << "\n";
			cout << l[ans_1[i].second] << ' ' << l[ans_2[i].second] << "\n";
		}

		for (i; i < ans_2.size() - 1; i += 2)
		{
			cout << l[ans_2[i].first] << ' ' << l[ans_2[i + 1].first] << "\n";
			cout << l[ans_2[i].second] << ' ' << l[ans_2[i + 1].second] << "\n";
		}
	}
}