#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
		x &= 1;
	}

	stack<int> stck;

	for (int x : a)
		if (stck.empty() || stck.top() != x)
			stck.push(x);
		else
			stck.pop();

	cout << (stck.size() <= 1 ? "YES\n" : "NO\n");
	return 0;
}