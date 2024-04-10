#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	if ((a == c && c == e) || (b == d && d == f)) {cout << 1; return 0;}
	if (a == c && (f >= max(b, d) || f <= min(b, d))) {cout << 2; return 0;}
	if (a == e && (d >= max(b, f) || d <= min(b, f))) {cout << 2; return 0;}
	if (c == e && (b >= max(d, f) || b <= min(d, f))) {cout << 2; return 0;}
	if (b == d && (e >= max(a, c) || e <= min(a, c))) {cout << 2; return 0;}
	if (b == f && (c >= max(a, e) || c <= min(a, e))) {cout << 2; return 0;}
	if (d == f && (a >= max(c, e) || a <= min(c, e))) {cout << 2; return 0;}
	cout << 3; return 0;
}