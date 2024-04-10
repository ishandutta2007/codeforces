#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, z;
	cin >> n >> z;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	for (int i = 0, j = n / 2; i < n / 2; ++i) {
		while (j < n && a[i] + z > a[j])
			++j;
		if (j++ >= n) {
			cout << i;
			return 0;
		}
	}
	cout << n / 2;
	return 0;
}