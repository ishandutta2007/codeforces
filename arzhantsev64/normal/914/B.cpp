#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		cnt[x]++;
	}
	for (auto i : cnt)
		if (i.second % 2) {
			cout << "Conan" << endl;
			return 0;
		}
	cout << "Agasa" << endl;
}