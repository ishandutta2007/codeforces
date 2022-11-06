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

	int a[4];
	int sum = 0;
	for (int i = 0; i < 4; i++) cin >> a[i], sum += a[i];
	if (sum % 2 == 0)
	{
		if (a[0] + a[1] == sum / 2 || a[0] + a[2] == sum / 2 || a[0] + a[3] == sum / 2 ||
			a[0] == sum / 2 || a[1] == sum / 2 || a[2] == sum / 2 || a[3] == sum / 2)
			cout << "YES";
		else cout << "NO";
	}
	else cout << "NO";
}