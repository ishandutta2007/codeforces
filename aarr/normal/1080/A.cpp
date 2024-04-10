#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
//	cout << ceil(n / k) << endl;
	cout << (int) ceil((double)2 * n / k) + (int) ceil((double)5 * n / k) + (int) ceil((double)8 * n / k);
	return 0;
}