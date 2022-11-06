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
pii a[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a, a + n);
	reverse(a, a + n);

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += i * a[i].first + 1;
	}

	cout << ans << "\n";
	for (int i = 0; i < n; i++)
		cout << a[i].second << ' ';

}