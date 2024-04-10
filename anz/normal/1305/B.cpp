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
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;

	vector<vector<int> > ans;

	vector <int> res;
	int lptr = 0, rptr = s.size() - 1;

	while (lptr < rptr)
	{
		while (lptr < s.size() && s[lptr] != '(') lptr++;
		while (rptr >= 0 && s[rptr] != ')') rptr--;

		if (lptr < rptr)
		{
			res.push_back(lptr + 1);
			res.push_back(rptr + 1);

			lptr++, rptr--;
		}
		else break;
	}

	if (res.size()) ans.push_back(res);

	cout << ans.size() << '\n';
	for (auto& v : ans)
	{
		sort(v.begin(), v.end());
		cout << v.size() << '\n';
		for (auto it : v) cout << it << ' ';
		cout << '\n';
	}
}