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

const ll MOD = 998244353;

int n;
ll a[100001];
ll new_a[100001];

ll new_sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	ll new_sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll t; cin >> t;
		a[i] = t;

		ll tmp = 0;
		ll ten = 1;
		while (t)
		{
			tmp += (t % 10 * ten) % MOD;
			tmp %= MOD;

			t /= 10;
			ten *= 100;
			ten %= MOD;
		}

		new_a[i] = tmp % MOD;

		new_sum += tmp;
		new_sum %= MOD;
	}

	cout << new_sum * n % MOD* 11 % MOD;
}