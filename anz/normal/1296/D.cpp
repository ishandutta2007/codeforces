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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, a, b, k;
vector <ll> s;

int main()
{
	cin >> n >> a >> b >> k;
	for (int i = 0; i < n; i++)
	{
		ll h; cin >> h;
		h %= a + b;
		if (h == 0) h = a + b;
		s.push_back((h - 1) / a);
	}
	sort(s.begin(), s.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (k - s[i] < 0) break;
		k -= s[i];
		ans++;
	}
	cout << ans;
}