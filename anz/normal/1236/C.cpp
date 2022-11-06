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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[301][301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;

	int c = 1;
	for (int j = 0; j < n; j++) for (int i = 0; i < n; i++)
	{
		if (j % 2 == 0) ans[i][j] = c;
		else ans[n-1-i][j] = c;
		c++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
		cout << "\n";
	}
}