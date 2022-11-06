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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;
set <int> ab[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		ab[s[i] - 'a'].insert(i + 1);
	}

	int q; cin >> q;
	while (q--)
	{
		int od; cin >> od;
		if (od == 1)
		{
			int pos; char c;
			cin >> pos >> c;
			
			char prev = s[pos-1];
			s[pos-1] = c;

			ab[prev - 'a'].erase(pos);
			ab[c - 'a'].insert(pos);
		}
		else
		{
			int l, r; cin >> l >> r;

			int res = 0;
			for (int i = 0; i < 26; i++)
			{
				auto lit = ab[i].lower_bound(l);
				auto rit = ab[i].upper_bound(r);

				if (lit != rit) res++;
			}

			cout << res << "\n";
		}
	}
}