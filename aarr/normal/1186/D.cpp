#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
bool d[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, sm = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = 0;
		double y;
		cin >> y;
		d[i] = true;
		if (y == (int) y) {
			d[i] = false;
		}
		a[i] = (int) y;
		if (d[i] == true && y < (double) 0) {
			a[i]--;
		}
		sm += a[i];
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == true && sm < 0) {
			sm++;
			a[i]++;
		}
		cout << a[i] << "\n";
	}
	return 0;
}