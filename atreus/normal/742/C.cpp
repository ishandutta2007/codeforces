#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int p[maxn];
bool visited[maxn];

ll gcd (ll a, ll b) {
	if (a > b)
		swap (a, b);
	if (a == 0)
		return b;
	return gcd (b % a, a);
}

ll lcm (ll a, ll b) {
	return a * b / gcd (a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	ll ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		int cnt = 0, fi = i, x = i;
		while (!visited[x]) {
			cnt ++;
			visited[x] = 1;
			x = p[x];
		}
		if (x == fi) {
			if (cnt % 2 == 1)
				ans = lcm (ans, cnt);

			else if (cnt % 2 == 0)
				ans = lcm (ans, cnt / 2);
		}
		else
			return cout << -1 << endl, 0;
	}
	cout << ans << endl;
}