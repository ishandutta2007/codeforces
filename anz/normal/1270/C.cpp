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

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;

	while (t--)
	{
		ll sum = 0;
		ll xr = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			ll a; cin >> a;
			sum += a, xr ^= a;
		}

		vector <ll> ans;
		ans.push_back(xr);
		sum += xr;
		ans.push_back(sum);

		cout << "2\n";
		for (auto it : ans) cout << it << ' ';
		cout << '\n';
	}
}