#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

const int N = 1005;

long long a[N];
long long b[N];
vector <pair <long long, int> > vec;
vector <pair <int, int> > ans;

int32_t main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] *= N;
		a[i] += i;
		b[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] < a[i]) {
				vec.push_back({b[j], j});
			}
		}
		sort(vec.begin(), vec.end());
		for (int j = (int) vec.size() - 1; j >= 0; j--) {
			int x = vec[j].second;
			swap(b[i], b[x]);
			ans.push_back({i, x});
		}
		vec.clear();
	}
	bool d = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (b[i] < b[j]) {
				d = false;
			}
		}
	}
	if (!d) {
		int x = 0;
		n /= x;
	}
	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.first << " " << p.second << '\n';
	}
	return 0;
}