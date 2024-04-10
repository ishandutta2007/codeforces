#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	vector <int> b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} for (int i = 0; i < m; i++) {
		cin >> b[i];
	} sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ml = 99999;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j] && a[i] < ml) {
				ml = a[i];
			}
		}
	} if (ml < 99999) {
		cout << ml;
		return 0;
	}
	else {
		ml = min(*a.begin(), *b.begin());
		ml *= 10;
		ml += max(*a.begin(), *b.begin());
	} cout << ml;

	return 0;

}