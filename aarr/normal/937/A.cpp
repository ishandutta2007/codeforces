#include <iostream>
using namespace std;

bool mark[605];
int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!mark[x] && x) {
			mark[x] = true;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}