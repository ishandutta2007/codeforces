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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string a, b; cin >> a >> b;
		sort(a.begin(), a.end());
		bool ans = false;
		for (int i = 0; i <= (int)b.size() - (int)a.size(); i++)
		{
			string tmp = b.substr(i, a.size());
			sort(tmp.begin(), tmp.end());
			if (a == tmp)
			{
				ans = true;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}