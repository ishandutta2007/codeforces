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

int n;
ll b[200001];
map<ll, ll> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		mp[b[i] - i] += b[i];
	}

	for (auto& it : mp)
	{
		ans = max(ans, it.second);
	}

	cout << ans;
}