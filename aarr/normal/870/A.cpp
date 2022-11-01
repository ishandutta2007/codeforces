#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


const int N = 10;

bool a[N];
bool b[N];

int main() {
	int n, m, ans = 100;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x] = true;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b[x] = true;
	}
	for (int i = 1; i < N; i++) {
		if (a[i] && b[i]) {
			ans = min(ans, i);
		}
		for (int j = 1; j < N; j++) {
			if (a[i] && b[j]) {
				ans = min(ans, i * 10 + j);
				ans = min(ans, j * 10 + i);
			}
		}
	}
	cout << ans;
}