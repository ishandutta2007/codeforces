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

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int a, b, c, d, k; cin >> a >> b >> c >> d >> k;

		int pen = (a - 1) / c + 1;
		int pencil = (b - 1) / d + 1;
		if (pen + pencil <= k) cout << pen << ' ' << pencil << "\n";
		else cout << "-1\n";
	}
}