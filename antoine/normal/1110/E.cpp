#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (ll &x : a)
		cin >> x;
	for (ll &x : b)
		cin >> x;

	adjacent_difference(a.begin(), a.end(), a.begin());
	adjacent_difference(b.begin(), b.end(), b.begin());
	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());
	cout << (a == b ? "Yes" : "No");
	return 0;
}