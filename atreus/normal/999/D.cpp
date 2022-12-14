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
int a[maxn], b[maxn];
stack <int> v[maxn], s;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[a[i] % m].push (i);
	}
	ll ans = 0;
	memset (b, -1, sizeof b);
	for (int _ = 0; _ < 2; _ ++) {
		for (int i = 0; i < m; i++) {
			while (v[i].size() < (n / m) and !s.empty()) {
				int u = s.top();
				s.pop();
				v[i].push (u);
				b[u] = i;
			}
			while (v[i].size() > (n / m)) {
				int u = v[i].top();
				v[i].pop();
				s.push (u);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1)
			continue;
		int u = b[i] + m - (a[i] % m);
		u %= m;
		ans += u;
		a[i] += u;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}