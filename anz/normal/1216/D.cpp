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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
ll a[200001];
ll rm[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;

	ll maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxNum = max(maxNum, a[i]);
	}

	ll g = -1;
	for (int i = 0; i < n; i++)
	{
		rm[i] = maxNum - a[i];
		if (rm[i] == 0) continue;
		if (g == -1) g = rm[i];
		else g = gcd(g, rm[i]);
	}

	ll www = -1;
	if (maxNum % g == 0)
		www = maxNum;
	else
		www = (maxNum / g + 1) * g;

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += (www - a[i]) / g;

	cout << ans << ' ' << g;
}