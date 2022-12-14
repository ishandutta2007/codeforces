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
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	ll n, x, ans = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		ll c;
		cin >> c;
		ll pok = (c ^ x);
		ans += a[pok];
		a[c] ++;
	}
	cout << ans << endl;
}