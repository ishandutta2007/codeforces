#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5, INF = 2000 * 1000 * 1000 + 7;
int n, k;

int a[N];

bool isval(int md) {
	long long s = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		if (a[i] < md) {
			s += md - a[i];
		}
	}
	return (s <= k);
	
}


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long dw = 0, up = INF;
	while (up - dw > 1) {
		int md = (dw + up) / 2;
		if (isval(md)) {
			dw = md;
		}
		else {
			up = md;
		}
	}
	cout << dw;
	
	return 0;
}