#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	int m = 1 << n;
	vector <int> b;
	b.push_back(0);
	vector <bool> usd(m + 1);
    usd[0] = true;
    if (x < m) {
        usd[x] = true;
    }
	for (int i = 1; i < m; i++) {
        if (x >= m) {
            b.push_back(i);
            continue;
        }
        else {
            if (usd[i]) {
                continue;
            }
            b.push_back(i);
            usd[x ^ i] = true;
            usd[i] = true;
        }
	}
	cout << b.size() - 1 << "\n";
	for (int i = 1; i < b.size(); i++) {
        cout << (b[i] ^ b[i - 1]) << " ";
	}
	return 0;
}