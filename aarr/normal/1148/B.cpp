#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500 * 1000 + 7;
const long long M = 1000ll * 1000 * 1000 * 1000;

long long a[N];
long long b[N];
int main() {
	int n, m, ta, tb, k;
	cin >> n;
	cin >> m;
	cin >> ta;
	cin >> tb;
	cin >> k;
	for (int i = 0; i < N; i++) {
		a[i] = M;
		b[i] = M;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0; i <= n && i <= k; i++) {
		int j = lower_bound(b, b + m, (a[i] + ta)) - b;
		//int x = min(k - i + j - 1, m - 1);
		//cout << i << " " << a[i] + ta << " " << j << endl;
		ans = max(b[k - i + j] + tb, ans); 
	}
	if (ans >= M)	
		cout << -1;
	else
		cout << ans;
	return 0;
}