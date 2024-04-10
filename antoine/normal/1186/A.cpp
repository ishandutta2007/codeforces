#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int a, b,c;
	cin >> a >> b >> c;

	cout << (a <= min(b, c) ? "Yes" : "No");

	return 0;
}