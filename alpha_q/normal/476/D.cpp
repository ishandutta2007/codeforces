#include <bits/stdc++.h> 

using namespace std;

long long n, k;

int main (int argc, char const *argv[]) {
	cin >> n >> k;
	cout << (6 * n - 1) * k << endl;
	for (int i = 1, j = 0; i <= n; ++i, j += 6) {
		cout << k * (j + 1) << " " << k * (j + 2) << " " << k * (j + 3) << " " << k * (j + 5) << endl;
	}
    return 0;
}