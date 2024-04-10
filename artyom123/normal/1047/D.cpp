#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if(n > m) {
        swap(n, m);
	}
	if(n == 1) {
        cout << (m / 6 * 3 + max(m % 6 - 3, 0) << 1);
        return 0;
	}
	if(n == 2) {
        if (m == 2) {
            cout << 0;
            return 0;
        }
        if (m == 3) {
            cout << 4;
            return 0;
        }
        if (m == 7) {
            cout << 12;
            return 0;
        }
        cout << (m << 1);
        return 0;
	}
	cout << ((1LL * n * m / 2) << 1);
	return 0;
}