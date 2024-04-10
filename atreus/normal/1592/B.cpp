#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int a[maxn], b[maxn];

void solveOne() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		if (abs(i - 0) < x and abs(n - 1 - i) < x and a[i] != b[i]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}