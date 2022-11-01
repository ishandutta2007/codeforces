#include <iostream>
#include <deque>
using namespace std;

const int N = 200 * 1000 + 5;

deque <int> a;
pair <int, int> ans[N];
int main() {
	int n, q;
	cin >> n;
	cin >> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 1; i <= 2 * n; i++) {
		int x = a[0], y = a[1];
		a.pop_front();
		a.pop_front();
		a.push_back(min(x, y));
		a.push_front(max(x, y));
		ans[i] = {x, y};
	}
	for (int i = 0; i < q; i++) {
		long long m;
		cin >> m;
		if (m < n)
			cout << ans[m].first << " " << ans[m].second << endl;
		else
			cout << ans[m % (n - 1) + n - 1].first << " " << ans[m % (n - 1) + n - 1].second << endl;
	}
	return 0;
}