#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, a;
	cin >> n >> a;
	int res;
	double mina = 10000;
	double an;
	for (int i = n; i >= 3; i--) {
		an = abs(a - ((n + 1 - i) * 180 / (double)n));
		//cerr << (n + 1 - i) * 180 / (double)n << endl;
		if (mina > an) {
			mina = an;
			res = i;
		}
	}
	cout << "1 2 " <<res << endl;
}