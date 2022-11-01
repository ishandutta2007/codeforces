#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5005;

int a[N];
int c1[N];
long long c2[N * 2];
long long ps[N * 2];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i && a[j] < a[i]; j++) {
			c1[a[i] - a[j]]++;
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			c2[i + j] += 1ll * c1[i] * c1[j];
		}
	}
	for(int i = 1; i < N * 2; i++) {
		ps[i] = ps[i - 1] + c2[i];
	}
	long double ans = 0;
	for (int i = 1; i < N; i++) {
		ans += 1ll * c1[i] * ps[i - 1];
	}
//	cout << ans << endl;
	for (int i = 1; i <= 3; i++) {
		ans /= n;
		ans /= (n - 1);
		ans *= 2;
	//	cout << ans << endl;
	}
	cout << fixed << ans;
	return 0;
}