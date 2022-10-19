#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n, k;
	cin >> n >> k;
	int gcd = k;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u; 
		gcd = __gcd(gcd, u);
	}
	for (int i = 0; i < k; i += gcd) {
		v.push_back(i);
	}
	cout << v.size() << endl;
	for (auto x : v) {
		cout << x << ' ';
	}
	return 0;
}