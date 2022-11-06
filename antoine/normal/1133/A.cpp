#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(const int x) {
	if (x < 10)
		return "0" + to_string(x);
	return to_string(x);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	char c;
	int h1, m1, h2, m2;
	cin >> h1 >> c >> m1 >> h2 >> c >> m2;

	const int t1 = h1 * 60 + m1;
	const int t2 = h2 * 60 + m2;
	const int t = (t1 + t2) / 2;
	cout << f(t / 60) << ":" << f(t % 60);
	return 0;
}