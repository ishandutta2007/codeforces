#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	cout << min(k - 1, n - k) + n - 1 + n + 1 + n;
	return 0;
}