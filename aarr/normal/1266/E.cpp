#include <iostream>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int b[N];
map <pair <int, int>, int> mp;

int main() {
	ios :: sync_with_stdio(false);
	long long ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, t, u;
		cin >> s >> t >> u;
		int x = mp[{s, t}];
		if (x != 0) {
			ans -= max(a[x] - b[x], 0);
			b[x]--;
			ans += max(a[x] - b[x], 0);
		}
		if (u != 0) {
			ans -= max(a[u] - b[u], 0);
			b[u]++;
			ans += max(a[u] - b[u], 0);
		}
		mp[{s, t}] = u;
		cout << ans << '\n';
	}
	return 0;
}