#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;
int n;

int a[N];
long long ps[N];

long double get(int x, int v) {
//	cout << "78 " << x << " " << v << endl;
	if (v == -1) {
		return -1;
	}
	long long s = ps[x] - ps[x - v - 1] + ps[n] - ps[n - v];
	long double ans = ((long double) s) / (2 * v + 1);
	return ans - a[x];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + a[i];
	}
	long double maxi = 0;
	pair <int, int> maxfor = {1, 0}; 
	for (int i = 1; i <= n; i++) {
		int dw = 0, up = min(i, n - i + 1);
	//	if (up == dw) {
	//		continue;
	//	}
	//	cout << "23 " << i << " " << dw << " " << up << endl;
		while (up - dw > 1) {
			int md = (dw + up) / 2;
			if (get(i, md) > get(i, md - 1)) {
				dw = md;
			}
			else {
				up = md;
			}
		}
	//	cout << "49 " << i << " " << dw << endl;
		if (get(i, dw) > maxi) {
			maxi = get(i, dw);
			maxfor = {i, dw};
		}
	}
//	cout << "73 " << maxfor.first << " " << maxfor.second << " " << maxi << endl;
	cout << maxfor.second * 2 + 1 << endl;
	for (int i = maxfor.first; maxfor.first - i <= maxfor.second; i--) {
		cout << a[i] << " ";
	}
	for (int i = n; n - i < maxfor.second; i--) {
		cout << a[i] << " ";
	}
	return 0;
}