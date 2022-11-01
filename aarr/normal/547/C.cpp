#include <iostream>
#include <vector>
using namespace std;

const int N = 200 * 1000 + 5, A = 500 * 1000 + 5;


vector <int> vec[A];
vector <pair <int, int> > d[A];
int a[N];
bool mark[N];
int cnt[A];

int get(int x, int y) {
	return (x >> y) & 1;
}
void f(int x) {
	int y = x;
//	cout << y << endl;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			vec[y].push_back(i);
		}
		while (x % i == 0) {
			x /= i;
		}
	}
	if (x > 1) {
		vec[y].push_back(x);
	}
	for (int mask = 0; mask < (1 << vec[y].size()); mask++) {
		int z = 1;
		for (int i = 0; i < vec[y].size(); i++) {
			if (get(mask, i)) {
				z *= vec[y][i];
			}
		}
		d[y].push_back({z, __builtin_popcount(mask) % 2});
	//	cout << "73 " << y << " " << z << endl;
	}
}
int main() {
	ios :: sync_with_stdio(false);
	for (int i = 1; i < A; i++) {
		f(i);
	}
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		if (!mark[x]) {
			int y = a[x];
			mark[x] = true;
			for (auto p : d[y]) {
				int z = p.first;
				if (p.second == 1) {
					ans -= cnt[z];
					cnt[z]++;
				}
				else {
					ans += cnt[z];
					cnt[z]++;
				}
			}
		}
		else {
			int y = a[x];
			mark[x] = false;
			for (auto p : d[y]) {
				int z = p.first;
				if (p.second == 1) {
					cnt[z]--;
					ans += cnt[z];
				}
				else {
					cnt[z]--;
					ans -= cnt[z];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}