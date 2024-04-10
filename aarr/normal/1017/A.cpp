#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1005;

pair <int, int> a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			int x;
			cin >> x;
			a[i].first -= x;
			a[i].second = i + 1;
		}
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i].second == 1)
			cout << i + 1;
	}
	return 0;
}