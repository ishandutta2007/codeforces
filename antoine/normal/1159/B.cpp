#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f(const vector<int> a) {

	int res = (int) 1e9;

	for (int i = 1; i < (int) a.size(); ++i)
		res = min(res, min(a[i], a[0]) / i);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int ans = f(a);
	reverse(a.begin(), a.end());
	ans = min(ans, f(a));

	cout << ans;

	return 0;
}