#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define all(a) (a).begin(), (a).end()
using namespace std;

long long mmin = 1e18;
vector<char> z(3);

void f1(long long a) {
	mmin = min(mmin, a);
}

void f2(long long a, long long b) {
	if (z[2] == '+') {
		f1(a + b);
	}
	else {
		f1(a * b);
	}
}

void f3(long long a, long long b, long long c) {
	if (z[1] == '+') {
		f2(a + b, c);
		f2(a, b + c);
		f2(a + c, b);
	}
	else {
		f2(a * b, c);
		f2(a, b * c);
		f2(a * c, b);
	}
}

void f4(long long a, long long b, long long c, long long d) {
	if (z[0] == '+') {
		f3(a + b, c, d);
		f3(a + c, b, d);
		f3(a + d, b, c);
		f3(a, b + c, d);
		f3(a, b + d, c);
		f3(a, b, c + d);
	}
	else {
		f3(a * b, c, d);
		f3(a * c, b, d);
		f3(a * d, b, c);
		f3(a, b * c, d);
		f3(a, b * d, c);
		f3(a, b, c * d);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long a, b, c, d;
	cin >> a >> b >> c >> d >> z[0] >> z[1] >> z[2];
	f4(a, b, c, d);
	cout << mmin;
	return 0;
}//gmgtvv