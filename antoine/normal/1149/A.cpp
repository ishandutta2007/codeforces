#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.rbegin(), a.rend());

	sort(a.begin() + 1, a.end());
	if (n >= 2) {
		sort(a.rbegin(), a.rend() - 2);
	}

	for (int x : a)
		cout << x << ' ';
	return 0;
}