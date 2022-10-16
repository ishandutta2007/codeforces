#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int n, a[N], sum;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	cout << sum << endl;
	return 0;
}