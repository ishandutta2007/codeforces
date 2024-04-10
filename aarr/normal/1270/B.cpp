#include <iostream>
#include <stack>
#define int long long
using namespace std;

const int N = 200 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
stack <int> st;
int32_t main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		pair <int, int> ans = {-1, -1};
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		/*bool b = true;
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) > 2 && b) {
			//	cout << i << " " << i + 1 << '\n';
			//	b = false;
				ans = {i, i + 1};
			}
		}
		for (int i = 2; i < n; i++) {
			if (abs(a[i] - a[i - 2]) > 3 && b) {
			//	cout << i - 1 << " " << i + 1 << '\n';
			//	b = false;
				ans = {i - 1, i + 1};
			}
		}
		for (int i = 3; i < n; i++) {
			if (abs(a[i] - a[i - 3]) > 4 && b) {
			//	cout << i - 2 << " " << i + 1 << '\n';
			//	b = false;
				ans = {i - 2, i + 1};
			}
		}*/
		int maxfor = 1, minfor = 1;
	//	a[1] = inf, a[0] = -1;
		for (int i = 2; i <= n; i++) {
		//	cout << "73 " << minfor << " " << maxfor << endl;
			if (minfor >= 2 && abs(a[minfor] - a[i]) >= i - minfor + 1) {
				ans = {minfor, i};
			}
			if (maxfor >= 2 && abs(a[maxfor] - a[i]) >= i - maxfor + 1) {
				ans = {maxfor, i};
			}
			if (a[i] >= a[maxfor]) {
				maxfor = i;
			}
			if (a[i] <= a[minfor]) {
				minfor = i;
			}
			if (abs(a[i] - a[i - 1]) >= 2) {
				ans = {i - 1, i};
			}
		}
		if (ans.first == -1) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES\n" << ans.first << " " << ans.second << '\n';
		}
	}
	return 0;
}