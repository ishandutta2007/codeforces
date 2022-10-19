#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, g, n;
	cin >> b >> g >> n;
	int max_a = b;
	int min_a = n - g;
	max_a = min(max_a, n);
	min_a = max(0, min_a);
	cout << max_a - min_a + 1 << endl;
}