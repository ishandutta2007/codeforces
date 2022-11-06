#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, ax, ay, bx, by, cx, cy;
	cin >> n >> ax >> ay >> bx>>by>>cx>>cy;
	bool ok1 = (bx < ax) == (cx < ax);
	bool ok2 = (by < ay) == (cy < ay);
	cout << (ok1 && ok2 ? "YES" : "NO") << '\n';
	return 0;
}