#include <bits/stdc++.h>
using namespace std;
#define int long long
int getnum(char a) {
	if (a == 'v') {
		return 0;
	}
	else if (a == '<') {
		return 1;
	}
	else if (a == '^') {
		return 2;
	}
	else if (a == '>') {
		return 3;
	}
}
signed main() {
	char a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int x;
	x = (4 + getnum(a) - getnum(b)) % 4;
	n = n % 4;
	if (n == x) {
		if ((n == 2) || (n == 0)) {
			cout << "undefined" << endl;
		}
		else {
			cout << "ccw" << endl;
		}
	}else if (n + x == 4) {
		cout << "cw" << endl;
	}
	else {
		cout << "undefined" << endl;
	}

	return 0;
	
}