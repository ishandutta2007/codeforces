#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;

	int n = (int) s.size();
	int c = count(s.begin(), s.end(), 'a');
	cout << min(n, 2 * c - 1);
	return 0;
}