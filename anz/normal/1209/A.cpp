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

	int n; cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++)
	{
		int t; cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	vector <int> c(n);
	for (int i = 0; i < n; i++)
	{
		if (c[i]) continue;
		ans++;
		for (int j = i; j < n; j++)
		{
			if (v[j] % v[i] == 0) c[j] = 1;
		}
	}
	cout << ans;
}