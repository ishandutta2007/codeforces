#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	const int c = count(s.begin(), s.end() - 10, '8');
	bool ans = c >= n - 10 - c;
	cout << (ans ? "YES" : "NO");
	return 0;
}