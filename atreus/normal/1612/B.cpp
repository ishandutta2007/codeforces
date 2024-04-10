#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;
const int mod = 998244353;

int arr[maxn];

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int ptr = 1;
	set<int> S;
	for (int i = 1; i <= n; i++)
		if (i != a and i != b)
			S.insert(i);
	arr[1] = a;
	arr[n/2 + 1] = b;
	for (int i = 2; i <= n/2; i++) {
		int idx = *S.rbegin();
		if (idx < a) {
			cout << -1 << '\n';
			return;
		}
		S.erase(idx);
		arr[i] = idx;
	}
	for (int i = n/2 + 2; i <= n; i++) {
		int idx = *S.begin();
		if (idx > b) {
			cout << -1 << '\n';
			return;
		}
		S.erase(idx);
		arr[i] = idx;
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " \n"[i == n];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		solve();
	}
}