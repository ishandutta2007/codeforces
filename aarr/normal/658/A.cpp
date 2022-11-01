#include <iostream>
using namespace std;

const int N = 50;

int p[N];
int t[N];
int main() {
	int n, c;
	cin >> n;
	cin >> c;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	int ans1 = 0, ans2 = 0, x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		x += t[i];
		ans1 += max(0, p[i] - c * x);
	//	x += t[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		y += t[i];
		ans2 += max(0, p[i] - c * y);
	//	y += t[i];
	}
	if (ans1 > ans2) {
		cout << "Limak" << endl;
	}
	if (ans2 > ans1) {
		cout << "Radewoosh" << endl;
	}
	if (ans2 == ans1)
		cout << "Tie" << endl;
//	cout << ans1 << " " << ans2 << endl;
	return 0;
}