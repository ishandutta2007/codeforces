#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int l[N];
int w[N];

int getw(long long s, long long e) {
	if (e % 2) {
		if (s % 2) {
			return 2;
		}
		return 1;
	}
	if (s * 2 > e) {
		if (s % 2 == e % 2) {
			return 2;
		}	
		return 1;
	}
	if (s * 4 > e) {
		return 1;
	}
	return getw(s, e / 4);
}

int getl(long long s, long long e) {
	if (s * 2 > e) {
		return 1;
	}
	return getw(s, e / 2);
}

int main() {
	int n;
	cin >> n;
	w[0] = 2, l[0] = 1;
	for (int i = 1; i <= n; i++) {
		long long s, e;
		cin >> s >> e;
		int x = getw(s, e), y = getl(s, e);
	//	cout << "73 " << x << " " << y << endl;
		if (x == 1) {
			w[i] = l[i - 1];
		}
		else {
			w[i] = w[i - 1];
		}
		if (y == 1) {
			l[i] = l[i - 1];
		}
		else {
			l[i] = w[i - 1];
		}
	}
	cout << (w[n] == 1) << " " << (l[n] == 1);
	
	return 0;
}