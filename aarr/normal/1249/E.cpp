#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
int b[N];
int dp1[N];
int dp2[N];
int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		cin >> b[i];
	}
	dp1[1] = 0;
	dp2[1] = inf;
	for (int i = 2; i <= n; i++) {
		dp1[i] = a[i] + min(dp1[i - 1], dp2[i - 1]);
		dp2[i] = min(b[i] + dp2[i - 1], b[i] + dp1[i - 1] + c);
	}
	for (int i = 1; i <= n; i++) {
		cout << min(dp1[i], dp2[i]) << " ";
	}
	return 0;
}