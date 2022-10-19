#include <bits/stdc++.h>

using namespace std;

const int N = 1;

int a, b, c, d;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c >> d;
	cout << 2*b+a+2+2*d+c+2+abs(c-a);
	return 0;
}