#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;

int a[N];
int ans = 0, n;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++) ans += (a[i + 1] - a[i] - 1);
	cout << ans << endl;
	return 0;
}