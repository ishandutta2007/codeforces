#include <iostream>
using namespace std;

const int N = 105, W = 2000 * 1000 * 1000 + 7;

long long po[N];

bool get(int m, int x) {
	
	long long y = po[x];
//	cout << "73 " << m << " " << x << " " << y << endl;
	if (x == 0) {
		if (m <= 1) {
			return true;
		}
		return false;
	}
	if (m > y) {
		return get(m - y, x - 1);
	}
	if (m <= y - m) {
	//	cout << 48 << endl;
		return get(m, x - 1);
	}
	return get(y - m, x - 1);
}

int main() {
	int w, m, i;
	cin >> w >> m;
	
	po[0] = 1;
	for (i = 1; i < N; i++) {
		po[i] = po[i - 1] * w;
		if (po[i] > W) {
			break;
		}
	}
	if (get(m, i)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}