#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	int a = 0, b = 0;

	while (n--) {

		char type;
		int x, y;
		cin >> type >> x >> y;
		if (x < y)
			swap(x, y);
		if (type == '+') {
			a = max(a, x);
			b = max(b, y);
		} else {
			assert(type == '?');
			cout << (a <= x && b <= y ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}