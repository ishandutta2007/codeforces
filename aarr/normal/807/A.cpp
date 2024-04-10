#include <iostream>
#include <map>
#include <set>
using namespace std;

const int N = 1005;

int x[N];
int y[N];

int main() {
	int n;
	cin >> n;
	bool a = false, b = false;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (x[i] != y[i]) {
			a = true;
		}
		if (i > 0 && x[i] > x[i - 1]) {
			b = true;
		}
	}
	if (a) {
		cout << "rated";
	}
	else {
		if (b) {
			cout << "unrated";
		}
		else {
			cout << "maybe";
		}
	}
	return 0;
}