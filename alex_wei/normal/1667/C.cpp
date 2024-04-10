#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int main() {
	cin >> n, m = (2 * n + 1) / 3, cout << m << endl;
	for(int i = 1, j = 1; i <= m; i++, j += 2) cout << i << " " << (j > m ? j - m + !(m & 1) : j) << endl;
	return 0;
}