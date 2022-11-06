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
ll arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;

	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		ll t; cin >> t;
		arr[i] = t;
		sum += t;
	}

	if (sum % 2)
	{
		cout << "NO";
		return 0;
	}

	sort(arr, arr + n);

	if (arr[n - 1] > sum - arr[n - 1])
		cout << "NO";
	else
		cout << "YES";
}