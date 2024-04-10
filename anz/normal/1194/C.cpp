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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		string s, t, p;
		cin >> s >> t >> p;

		int s_cnt[26] = { 0, }, t_cnt[26] = { 0, }, p_cnt[26] = { 0, };
		for (int i = 0; i < s.size(); i++) s_cnt[s[i] - 'a']++;
		for (int i = 0; i < t.size(); i++) t_cnt[t[i] - 'a']++;
		for (int i = 0; i < p.size(); i++) p_cnt[p[i] - 'a']++;

		int s_ptr = 0, t_ptr = 0;
		while (s_ptr < s.size() && t_ptr < t.size())
		{
			if (s[s_ptr] == t[t_ptr])
				s_ptr++, t_ptr++;
			else
				t_ptr++;
		}

		if (s_ptr != s.size())
		{
			cout << "NO\n";
			continue;
		}

		for (int i = 0; i < 26; i++)
		{
			t_cnt[i] -= s_cnt[i];
		}

		bool flag = true;
		for (int i = 0; i < 26; i++)
		{
			if (t_cnt[i] > p_cnt[i])
			{
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}