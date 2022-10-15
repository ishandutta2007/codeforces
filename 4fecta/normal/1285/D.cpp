#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ans = 0;
vector<int> v;
int rec(int s, vector<int> vals) {
	if (s < 0) return 0;
	vector<int> v0, v1;
	for (int val : vals) val & (1 << s) ? v1.push_back(val) : v0.push_back(val);
	if (v0.empty()) return rec(s - 1, v1);
	if (v1.empty()) return rec(s - 1, v0);
	return min(rec(s - 1, v0), rec(s - 1, v1)) + (1 << s);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]);
	printf("%d\n", rec(30, v));
}