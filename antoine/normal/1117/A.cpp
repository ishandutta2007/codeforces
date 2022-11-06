#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	const int m = *max_element(a.begin(), a.end());
	int ans = 0, curr = 0;
	for (int &x : a)
		if (x == m)
			ans = max(ans, ++curr);
		else
			curr = 0;
	cout << ans;
	return 0;
}