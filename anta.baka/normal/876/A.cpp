#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << min({a * (n - 1), b * (n - 1), min(a, b) + c * max(0, n - 2)});
}