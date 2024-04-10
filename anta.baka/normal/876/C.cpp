#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int n) {
	int ret = 0;
	while(n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> v;
	for(int i = n; i >= max(1, n - 1000); i--)
		if(i + f(i) == n)
			v.push_back(i);
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(int x : v) cout << x << '\n';
}