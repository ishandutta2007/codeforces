#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


const int N = 105;
int cnt[N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, ans = N * N * N;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cnt[i];
	}
	for (int i = 0; i < n; i++) {
		int s = 3 * cnt[i];
		for (int j = 0; j < cnt[i]; j++) {
			int x;
			cin >> x;
			s += x;
		}
		ans = min(ans, s);
	}
	cout << ans * 5;
}